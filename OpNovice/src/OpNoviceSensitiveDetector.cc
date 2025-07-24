#include "OpNoviceSensitiveDetector.hh"
#include "G4Step.hh"
#include "G4ParticleDefinition.hh"
#include "G4OpticalPhoton.hh"
#include "G4VProcess.hh"
#include "G4OpBoundaryProcess.hh"
#include "G4ProcessManager.hh"
#include "G4ProcessVector.hh"
#include "G4StepPoint.hh"
#include "G4Track.hh"

OpNoviceSensitiveDetector::OpNoviceSensitiveDetector(OpNoviceEventAction* eventAction)
    : G4VSensitiveDetector("OpNoviceSensitiveDetector"), eventAction_(eventAction)
{
}

G4bool OpNoviceSensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory*)
{
    std::cout << "Processing hit in OpNoviceSensitiveDetector" << std::endl;
    static G4ParticleDefinition* opticalphoton = G4OpticalPhoton::Definition();

  const G4ParticleDefinition* particleDef =
    step->GetTrack()->GetDynamicParticle()->GetParticleDefinition();

  if (particleDef != opticalphoton)
    return false;

  G4StepPoint* endPoint = step->GetPostStepPoint();
  const G4VProcess* pds = endPoint->GetProcessDefinedStep();
  if (!pds)
    return false;

  const G4String& procname = pds->GetProcessName();

  if (procname == "OpRayleigh")
    eventAction_->AddRayleigh();
  else if (procname == "OpAbsorption")
    eventAction_->AddAbsorption();
  else if (procname == "OpMieHG")
    eventAction_->AddMie();

  if (endPoint->GetStepStatus() == fGeomBoundary)
  {
    G4OpBoundaryProcessStatus theStatus = Undefined;
    G4ProcessManager* opManager = opticalphoton->GetProcessManager();
    G4int n_proc = opManager->GetPostStepProcessVector(typeDoIt)->entries();
    G4ProcessVector* postStepDoItVector = opManager->GetPostStepProcessVector(typeDoIt);

    for (G4int i = 0; i < n_proc; ++i)
    {
      G4VProcess* currentProcess = (*postStepDoItVector)[i];
      if (auto opProc = dynamic_cast<G4OpBoundaryProcess*>(currentProcess))
      {
        theStatus = opProc->GetStatus();
      }
    }

    if (theStatus != Undefined && theStatus != NotAtBoundary && theStatus != StepTooSmall)
    {
      eventAction_->AddBoundary();
    }
  }
  //  auto edep = step->GetTotalEnergyDeposit();
  //  if (edep > 0)
  //  {
  //      // Example: send energy to eventAction if desired
  //      // eventAction_->AddEdep(edep);
  //  }
    return true;
}

