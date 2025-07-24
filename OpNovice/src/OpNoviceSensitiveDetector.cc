#include "OpNoviceSensitiveDetector.hh"
#include "OpNoviceEventAction.hh"
#include "G4StepPoint.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"
#include <iostream>

OpNoviceSensitiveDetector::OpNoviceSensitiveDetector(OpNoviceEventAction* eventAction)
    : G4VSensitiveDetector("OpNoviceSensitiveDetector"), eventAction_(eventAction)
{
}

G4bool OpNoviceSensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory*)
{
    std::cout << "Processing hit in OpNoviceSensitiveDetector" << std::endl;
  //  auto edep = step->GetTotalEnergyDeposit();
  //  if (edep > 0)
  //  {
  //      // Example: send energy to eventAction if desired
  //      // eventAction_->AddEdep(edep);
  //  }
    return true;
}

