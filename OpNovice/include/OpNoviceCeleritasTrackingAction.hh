#include "G4UserTrackingAction.hh"
#include "globals.hh"

class OpNoviceCeleritasTrackingAction : public G4UserTrackingAction
{
  public:
    OpNoviceCeleritasTrackingAction();
    virtual ~OpNoviceCeleritasTrackingAction();

    virtual void PreUserTrackingAction(const G4Track* track) override;
    virtual void PostUserTrackingAction(const G4Track* track) override;
};