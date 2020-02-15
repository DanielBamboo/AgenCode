// -*-c++-*-

#ifndef SAMPLE_PLAYER_H
#define SAMPLE_PLAYER_H

#include "action_generator.h"
#include "field_evaluator.h"
#include "communication.h"

#include <rcsc/player/player_agent.h>
#include <vector>

class SamplePlayer
    : public rcsc::PlayerAgent {
private:

    Communication::Ptr M_communication;

    FieldEvaluator::ConstPtr M_field_evaluator;
    ActionGenerator::ConstPtr M_action_generator;

public:

    SamplePlayer();

    virtual
    ~SamplePlayer();

protected:

    /*!
      You can override this method.
      But you must call PlayerAgent::initImpl() in this method.
    */
    virtual
    bool initImpl( rcsc::CmdLineParser & cmd_parser );

    //! main decision
    virtual
    void actionImpl();

    //! communication decision
    virtual
    void communicationImpl();

    virtual
    void handleActionStart();
    virtual
    void handleActionEnd();

    virtual
    void handleServerParam();
    virtual
    void handlePlayerParam();
    virtual
    void handlePlayerType();

    virtual
    FieldEvaluator::ConstPtr createFieldEvaluator() const;

    virtual
    ActionGenerator::ConstPtr createActionGenerator() const;

private:

    bool doPreprocess();
    bool doShoot();
    bool doForceKick();
    bool doHeardPassReceive();

public:
    virtual
    FieldEvaluator::ConstPtr getFieldEvaluator() const;
};

#endif
