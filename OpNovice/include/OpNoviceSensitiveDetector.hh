
#include "G4VSensitiveDetector.hh"
#include "G4Step.hh"
#include "G4TouchableHistory.hh"
#include <G4String.hh>

#include "OpNoviceEventAction.hh"



#include "G4VSensitiveDetector.hh"
#include "G4Step.hh"
#include "G4TouchableHistory.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"
#include "G4String.hh"
#include "G4HCofThisEvent.hh"
class OpNoviceSensitiveDetector : public G4VSensitiveDetector
{
 public:
     OpNoviceSensitiveDetector(const G4String& name, OpNoviceEventAction* eventAction);
    virtual ~OpNoviceSensitiveDetector() = default;
    void EndOfEvent(G4HCofThisEvent*) override;


  //  OpNoviceSensitiveDetector(const G4String& name);
  //  ~OpNoviceSensitiveDetector() override = default;
//
    virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history) override;
 private:
    OpNoviceEventAction* eventAction_ = nullptr;  // to access counters
    private:
    G4int fRayleighCount = 0;
    G4int fAbsorptionCount = 0;
    G4int fMieCount = 0;
    G4int fBoundaryCount = 0;
    G4int fScintillationCount = 0;
    G4int fCerenkovCount = 0;

};
