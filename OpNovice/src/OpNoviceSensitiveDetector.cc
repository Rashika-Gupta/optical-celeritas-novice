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
#include "OpNoviceEventAction.hh"
#include "OpNoviceRun.hh"
#include "G4RunManager.hh"
OpNoviceSensitiveDetector::OpNoviceSensitiveDetector(const G4String& name, OpNoviceEventAction* eventAction)
    : G4VSensitiveDetector(name), eventAction_(eventAction)
{
   
}

//OpNoviceSensitiveDetector::OpNoviceSensitiveDetector(const G4String& name)
//    : G4VSensitiveDetector(name)
//{}

G4bool OpNoviceSensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory*)
{
    static G4ParticleDefinition* opticalphoton = G4OpticalPhoton::Definition();
//std::cout << "Processing hit in OpNoviceSensitiveDetector" << std::endl;
    const G4ParticleDefinition* particleDef = step->GetTrack()->GetDynamicParticle()->GetParticleDefinition();

    if (particleDef != opticalphoton)
        return false;

    G4StepPoint* endPoint = step->GetPostStepPoint();
    const G4VProcess* pds = endPoint->GetProcessDefinedStep();
    if (!pds)
        return false;
    
    const G4String& procname = pds->GetProcessName();
   
   if (procname == "OpRayleigh")
        ++fRayleighCount;
    else if (procname == "OpAbsorption")
        ++fAbsorptionCount;
    else if (procname == "OpMieHG")
        ++fMieCount;
  

    G4Track* aTrack = step->GetTrack();
    if (aTrack->GetDefinition() == G4OpticalPhoton::OpticalPhotonDefinition())
    {  // particle is optical photon
        if (aTrack->GetParentID() > 0){  // particle is secondary
          if (aTrack->GetCreatorProcess()->GetProcessName() == "Scintillation")
          //  std::cout << "Scintillation photon detected" << std::endl;  
          ++fScintillationCount;
          else if (aTrack->GetCreatorProcess()->GetProcessName() == "Cerenkov")
            //std::cout << "Cerenkov photon detected" << std::endl;
            ++fCerenkovCount;
        }
    }
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
    }  
    return true;
}
void OpNoviceSensitiveDetector::EndOfEvent(G4HCofThisEvent*)
{
    auto run = static_cast<OpNoviceRun*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
    run->AddRayleigh(fRayleighCount);
    run->AddAbsorption(fAbsorptionCount);
    run->AddMie(fMieCount);
    run->AddBoundary(fBoundaryCount);
    run->AddScintillation(fScintillationCount);
    run->AddCerenkov(fCerenkovCount);
    fRayleighCount = fAbsorptionCount = fMieCount = fBoundaryCount  =fScintillationCount = fCerenkovCount = 0;
}