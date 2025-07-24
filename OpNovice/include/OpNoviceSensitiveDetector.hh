
#include "G4VSensitiveDetector.hh"
#include "G4Step.hh"
#include "G4TouchableHistory.hh"
#include <G4String.hh>

#include "OpNoviceEventAction.hh"

class OpNoviceSensitiveDetector : public G4VSensitiveDetector
{
  public:
   OpNoviceSensitiveDetector();
  
   ~OpNoviceSensitiveDetector() override = default;
   explicit OpNoviceSensitiveDetector(OpNoviceEventAction* eventAction);

    G4bool ProcessHits(G4Step* step, G4TouchableHistory* history) override;

  private:
    OpNoviceEventAction* eventAction_;
};
