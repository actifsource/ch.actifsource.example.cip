/*********************************************************************
  SYSTEM HistorystateSystem
  IMPLEMENTATION Historystate_cpp
  Error Header File for CIP MACHINE mHistorystateSUnit
  Filename: mainHistorystateSystem_TestSuite_Console.cpp
  generated by CIP Tool(R)
  
  activated code options:
  	C++ code
  	use message interface
              naming option: channel  prefix
          all types in shell
          'unsigned long' for delays  
*********************************************************************/

/* Begin Protected Region [[include]] */

/* End Protected Region   [[include]] */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "FCTY_mHistorystateSUnit.hpp"


using namespace std;

namespace dec
{

	/** Enum to specify the animation mode. */
	typedef enum EAnimationMode
	{
	  eAnimationMode_Undefined,
	  eAnimationMode_Manual,
	  eAnimationMode_Regressive,  
	  eAnimationMode_Runner
	} T_EAnimationMode;
	
	/** Enum to specify the trace mode. */
	typedef enum ETraceMode
	{
	  eTrace_Disable,
	  eTrace_Enable
	} T_ETraceMode;
	
	/** Enum variable to specify the animation mode. */
	T_EAnimationMode g_eAnimationMode = eAnimationMode_Undefined;
	
	/** Enum variable to specify the trace mode. */
	T_ETraceMode g_eTraceMode = eTrace_Disable;
	
	/** Enum for all event messages of this system. */
	typedef enum EEventMessage
	{
	  eEventMessage_Quit = -1,
	  eEventMessage_Tick = 0,
	  eEventMessage_Step,
  	  eEventMessage_TimeUp,
	  eEventMessage_Chain,
	  eEventMessage_Read,
	  eEventMessage_Auto,
	  eEventMessage_Event_1_powerOn,
	  eEventMessage_Event_1_powerOff,
	  eEventMessage_Event_1_doMachineStuff,
	  eEventMessage_Event_1_nextWorkload,
	  eEventMessage_Event_1_powerFail,
	  eEventMessage_Event_2_powerOn,
	  eEventMessage_Event_2_powerOff,
	  eEventMessage_Event_2_doMachineStuff,
	  eEventMessage_Event_2_nextWorkload,
	  eEventMessage_Event_2_powerFail,
	  eEventMessageCount
	} T_EEventMessage; 
	
	/** Enum for all action messages of this system. */
	typedef enum EActionMessage
	{
	  eActionContextError = 0,
	  eActionFullBufferWarning,
	  eActionBufferError,
	  eActionPulseSelectionError,
	  eActionMessageSelectionError,
	  eActionInputError,
	  eActionMessageCount
	} T_EActionMessage; 
	
	/** Enum for all test case. */
	typedef enum ETestCase
	{
  	  eTestCase_SimpleMachineProcessTest,
  	  eTestCase_ComplexMachineProcessTest
	} T_ETestCase;

	/* Checked output message */
	const int checkedOutputMessage_SimpleMachineProcessTest[eActionMessageCount] = {1, 1, 1, 1, 1, 1};
	const int checkedOutputMessage_ComplexMachineProcessTest[eActionMessageCount] = {1, 1, 1, 1, 1, 1};

	/** Typedef of all Event data. */
	typedef union UEventData
	{
	  int tick;
	} T_UEventData;
	
	
	
	
	/** Recorded action message of this system. */
	typedef struct SRecordedActionMessage
	{
	  T_EActionMessage actionMessage;
	} T_RecordedActionMessage;
	
	/** Maximum action messages which can be recorded per event message for automatic animation. */
	enum {g_nMaxRecordedActionMessageCount = 100};
	
	/** The number of recorded action messages. */
	int g_nRecordedActionMessageCount = 0;
	
	/** The number of expected action messages. */
	int g_nExpectedActionMessageCount = 0;
	
	/** An array which contains the recorded action messages. */
	T_RecordedActionMessage g_eRecordedActionMessage[g_nMaxRecordedActionMessageCount];
	
	/** System Tick. */
	int s_nSystemTick = 0;
	

	/* Active Test Case */
	T_ETestCase activeTestCase;
	
	/**
	 * Checked output message
	 */
	char isCheckedOutputMessage(T_EActionMessage i_eActionMessage)
	{
	  switch (activeTestCase)
	  {
	     case eTestCase_SimpleMachineProcessTest:
	       return checkedOutputMessage_SimpleMachineProcessTest[i_eActionMessage];
	     case eTestCase_ComplexMachineProcessTest:
	       return checkedOutputMessage_ComplexMachineProcessTest[i_eActionMessage];
	     default:
	       return 0;
	     break;
	  }
	  return 1;
	}

	/**
	 *  Translates the given action message enum to string.
	 *  @param i_eActionMessage The message type to translate.
	 *  @return The translated action message or 0 if enum not found.
	 */
	const char* const translateActionMessage(T_EActionMessage i_eActionMessage)
	{
	  switch (i_eActionMessage)
	  {
	    case eActionMessageCount:
	      return 0;
	    break;
	    default:
	      return 0;
	    break;
	  }
	  return 0;
	}
	
	/**
	 *  Check if the Action message has equals data.
	 *  @param i_eActionMessage The message type to translate.
	 *  @return The action message is equals 1 or 0 if not.
	 */
	char equalsActionMessageData(T_RecordedActionMessage sActionMessage, T_RecordedActionMessage sRecordedActionMessage)
	{
	  switch (sRecordedActionMessage.actionMessage)
	  {
	    case eActionMessageCount:
	      return 1;
	    break;
	    default:
	      return 1;
	    break;
	  }
	  return 1;
	}
	
	/**
	 *  Check if the Action message has equals index.
	 *  @param i_eActionMessage The message type to translate.
	 *  @return The action message is equals 1 or 0 if not.
	 */
	char equalsActionMessageIndex(T_RecordedActionMessage sActionMessage, T_RecordedActionMessage sRecordedActionMessage)
	{
	  switch (sRecordedActionMessage.actionMessage)
	  {
	    case eActionMessageCount:
	      return 1;
	    break;
	    default:
	      return 1;
	    break;
	  }
	  return 1;
	}
	
	/**
	 *  Records the message action from the cip system.
	 *  @param i_eActionMessage The message type to record.
	 */
	void recordMessageAction(T_RecordedActionMessage sRecordedActionMessage)
	{
	  if (g_nRecordedActionMessageCount>=g_nMaxRecordedActionMessageCount) {return;}
	  g_eRecordedActionMessage[g_nRecordedActionMessageCount++] = sRecordedActionMessage;
	}
	
	/**
	 *  Asserts the message action from the cip system.
	 *  @param i_eActionMessage The action message type to compare.
	 *  @param i_pcTestEventGuid The guid of the test event.
	 *  @param i_pcActionMessageGuid The guid of the action message to compare.
	 *  @return 1 if recoreded and expected message actions are equal. 0 if not.
	 *  @warning Previously record message actions with recordMessageAction()
	 */
	int assertMessageAction(T_RecordedActionMessage sRecordedActionMessage, const char* const i_pcTestEventGuid, const char* const i_pcActionMessageGuid, const char* const i_testCaseName, int checkData)
	{
	  if (g_nExpectedActionMessageCount >= g_nRecordedActionMessageCount) 
	  {
	    if (g_eAnimationMode == eAnimationMode_Runner) {
	    	printf("f0198f98-9ac0-11ef-9dfa-835f60e5a95d.asr: Failure\n");
	    	printf("TestCase: %s\n", i_testCaseName);
	    }
	    printf("    ASSERTION FAILED: %s\n",i_pcTestEventGuid);
	    printf("    > Expected: ActionMessage #%i = %s %s\n", g_nExpectedActionMessageCount, translateActionMessage(sRecordedActionMessage.actionMessage), i_pcActionMessageGuid);
	    printf("    > Recorded: -\n");
	    return 0;
	  }
	  T_RecordedActionMessage sActionMessage = g_eRecordedActionMessage[g_nExpectedActionMessageCount++];
	  if (sActionMessage.actionMessage != sRecordedActionMessage.actionMessage)
	  {
	    if (g_eAnimationMode == eAnimationMode_Runner) {
	    	printf("f0198f98-9ac0-11ef-9dfa-835f60e5a95d.asr: Failure\n");
	    	printf("TestCase: %s\n", i_testCaseName);
	    }
	    printf("    ASSERTION FAILED: %s\n",i_pcTestEventGuid);
	    printf("    > Expected: ActionMessage #%i = %s %s\n", g_nExpectedActionMessageCount, translateActionMessage(sRecordedActionMessage.actionMessage), i_pcActionMessageGuid);
	    printf("    > Recorded: ActionMessage #%i = %s\n", g_nExpectedActionMessageCount, translateActionMessage(sActionMessage.actionMessage));
	    return 0;
	  }
	  if (!equalsActionMessageIndex(sActionMessage, sRecordedActionMessage)) 
	  {
	    if (g_eAnimationMode == eAnimationMode_Runner) {
	    	printf("f0198f98-9ac0-11ef-9dfa-835f60e5a95d.asr: Failure\n");
	    	printf("TestCase: %s\n", i_testCaseName);
	    }
	    printf("    ASSERTION FAILED: %s\n",i_pcTestEventGuid);
	    printf("    > Expected: ActionMessage index not equals #%i = %s %s\n", g_nExpectedActionMessageCount, translateActionMessage(sRecordedActionMessage.actionMessage), i_pcActionMessageGuid);
	    printf("    > Recorded: ActionMessage index not equals #%i = %s\n", g_nExpectedActionMessageCount, translateActionMessage(sActionMessage.actionMessage));
	    return 0;
	  }
	  if (!checkData) return 1;
	  if (!equalsActionMessageData(sActionMessage, sRecordedActionMessage)) 
	  {
	    if (g_eAnimationMode == eAnimationMode_Runner) {
	    	printf("f0198f98-9ac0-11ef-9dfa-835f60e5a95d.asr: Failure\n");
	    	printf("TestCase: %s\n", i_testCaseName);
	    }
	    printf("    ASSERTION FAILED: %s\n",i_pcTestEventGuid);
	    printf("    > Expected: ActionMessage data not equals #%i = %s %s\n", g_nExpectedActionMessageCount, translateActionMessage(sRecordedActionMessage.actionMessage), i_pcActionMessageGuid);
	    printf("    > Recorded: ActionMessage data not equals #%i = %s\n", g_nExpectedActionMessageCount, translateActionMessage(sActionMessage.actionMessage));
	    return 0;
	  }
	  return 1;
	}
	
	/**
	 *  Asserts and resets the message action count variable.
	 *  @param i_pcTestEventGuid The guid of the test event.
	 *  @return 1 if recoreded and expected message action counts are equal. 0 if not.
	 */
	int assertMessageActionCount(const char* const i_pcTestEventGuid, const char* const i_testCaseName)
	{
	  int bEqualMessageActionCount = g_nExpectedActionMessageCount == g_nRecordedActionMessageCount;
	  if (!bEqualMessageActionCount)
	  {
	    if (g_eAnimationMode == eAnimationMode_Runner) {
	    	printf("f0198f98-9ac0-11ef-9dfa-835f60e5a95d.asr: Failure\n");
	    	printf("TestCase: %s\n", i_testCaseName);
	    }
	    printf("    ASSERTION FAILED: %s\n",i_pcTestEventGuid);
	    printf("    > Expected: -\n");
	    for (;g_nExpectedActionMessageCount<g_nRecordedActionMessageCount;++g_nExpectedActionMessageCount)
	    {
	      printf("    > Recorded: ActionMessage #%i = %s\n", g_nExpectedActionMessageCount+1,translateActionMessage(g_eRecordedActionMessage[g_nExpectedActionMessageCount].actionMessage));
	    }
	  }
	  g_nRecordedActionMessageCount = 0;
	  g_nExpectedActionMessageCount = 0;
	  return bEqualMessageActionCount;
	}


	/** 
	 * class ActionInitiation
	 */	
	class ActionInitiation :	 
		public historystatesunit::cipshell::INTF_ActionMessagePort
	{
	public:
	};


	/** Action Message implementation */
	// The action handler
	ActionInitiation amp;
	
	// Pointer to the CIP Machine
	historystatesunit::cipshell::INTF_mHistorystateSUnit* m_cipmachine;

	/** CIP Machine Initialization Function */
	int fINIT_Machine(void)
	{
		if (m_cipmachine != NULL) {
			delete m_cipmachine;
		}
		m_cipmachine = historystatesunit::cipshell::FCTY_mHistorystateSUnit::cipmachine(&amp);
		return true;
	} // fINIT_Machine()

	/**
	 *  Function forward.
	 */
	void sendTickEvent(int i_nTickCount, int i_bAutoTimeup);
	void sendStepEvent();
	void sendChainEvent();
	void sendAutoEvent();
	void sendTimeupEvent();
	void sendReadEvent();
	
	/** 
	 *  Sends the message event to the cip system.
	 *  @param i_eEventMessage The message type to send.
	 *  @param i_bAutoStep Automatically calls STEP_ if 1. Calls STEP_ for all pending events if code option enable_PENDING_Information set.
	 *  @return 1 if ok. 0 if failed.
	 */
	int sendMessageEvent(T_EEventMessage i_eEventMessage, int i_bAutoStep, int i_bAutoTimeup, T_UEventData *eventData )
	{
	  switch (i_eEventMessage)
	  {
	    case eEventMessage_Tick:
      	      sendTickEvent(eventData->tick, i_bAutoTimeup);
	    break;
	    case eEventMessage_Step:
	      sendStepEvent();
	    break;
	    case eEventMessage_TimeUp:
	      sendTimeupEvent();
	    break;
	    case eEventMessage_Chain:
	      sendChainEvent();
	    break;
	    case eEventMessage_Read:
	      sendReadEvent();
	    break;
	    case eEventMessage_Auto:
	      sendAutoEvent();
	    break;
	    case eEventMessage_Event_1_powerOn:
	      if (g_eTraceMode == eTrace_Enable) {printf(" EventMessage: powerOn  \n");}
	      m_cipmachine->C1_powerOn();
	    break;
	    case eEventMessage_Event_1_powerOff:
	      if (g_eTraceMode == eTrace_Enable) {printf(" EventMessage: powerOff  \n");}
	      m_cipmachine->C1_powerOff();
	    break;
	    case eEventMessage_Event_1_doMachineStuff:
	      if (g_eTraceMode == eTrace_Enable) {printf(" EventMessage: doMachineStuff  \n");}
	      m_cipmachine->C1_doMachineStuff();
	    break;
	    case eEventMessage_Event_1_nextWorkload:
	      if (g_eTraceMode == eTrace_Enable) {printf(" EventMessage: nextWorkload  \n");}
	      m_cipmachine->C1_nextWorkload();
	    break;
	    case eEventMessage_Event_1_powerFail:
	      if (g_eTraceMode == eTrace_Enable) {printf(" EventMessage: powerFail  \n");}
	      m_cipmachine->C1_powerFail();
	    break;
	    case eEventMessage_Event_2_powerOn:
	      if (g_eTraceMode == eTrace_Enable) {printf(" EventMessage: powerOn  \n");}
	      m_cipmachine->C2_powerOn();
	    break;
	    case eEventMessage_Event_2_powerOff:
	      if (g_eTraceMode == eTrace_Enable) {printf(" EventMessage: powerOff  \n");}
	      m_cipmachine->C2_powerOff();
	    break;
	    case eEventMessage_Event_2_doMachineStuff:
	      if (g_eTraceMode == eTrace_Enable) {printf(" EventMessage: doMachineStuff  \n");}
	      m_cipmachine->C2_doMachineStuff();
	    break;
	    case eEventMessage_Event_2_nextWorkload:
	      if (g_eTraceMode == eTrace_Enable) {printf(" EventMessage: nextWorkload  \n");}
	      m_cipmachine->C2_nextWorkload();
	    break;
	    case eEventMessage_Event_2_powerFail:
	      if (g_eTraceMode == eTrace_Enable) {printf(" EventMessage: powerFail  \n");}
	      m_cipmachine->C2_powerFail();
	    break;
	    default:
	      return 0;
	    break;
	  }
	  {
    	    if (g_eTraceMode == eTrace_Enable) {printf(" STEP_\n");}
    	    int maxStepCount = 0;
    	    for (maxStepCount=0;maxStepCount<i_bAutoStep;maxStepCount++) 
    	    {
      	      m_cipmachine->STEP_();
    	    }
  	  }
	  return 1;
	}
	
	/** 
	 *  Sends the tick event to the cip system.
	 *  @param i_nTickCount The number of ticks.
	 *  @param i_bAutoTimeup Calls TIMEUP_ after each tick if set.
	 */
	void sendTickEvent(int i_nTickCount, int i_bAutoTimeup)
	{
	  int nTickCount;
	  int nAutoCount;
	  if (g_eTraceMode == eTrace_Enable) {printf(" START TICK_ #%i\n",s_nSystemTick);}
	  for (nTickCount=0;nTickCount<i_nTickCount;++nTickCount)
	  {
	    s_nSystemTick++;
	    m_cipmachine->TICK_(); 
	    for(nAutoCount=0;nAutoCount<i_bAutoTimeup;nAutoCount++)  
    	    {
	       m_cipmachine->TIMEUP_();
	    }
	  }  
	  if (g_eTraceMode == eTrace_Enable) {printf(" END TICK_ #%i\n",s_nSystemTick);}
	}
	
	/** 
	 *  Sends the step event to the cip system.
	 */
	void sendStepEvent()
	{
	  if (g_eTraceMode == eTrace_Enable) {printf(" STEP_\n");}
	  m_cipmachine->STEP_();
	}
	
	/** 
	 *  Sends the chain event to the cip system.
	 */
	void sendChainEvent()
	{
	  if (g_eTraceMode == eTrace_Enable) {printf(" CHAIN_\n");}
	  m_cipmachine->CHAIN_(); 
	}
	
	/** 
	 *  Sends the timeup event to the cip system.
	 */
	void sendTimeupEvent()
	{
	  if (g_eTraceMode == eTrace_Enable) {printf(" TIMEUP_\n");}
	  m_cipmachine->TIMEUP_(); 
	}
	
	/** 
	 *  Sends the read event to the cip system.
	 */
	void sendReadEvent()
	{
	  if (g_eTraceMode == eTrace_Enable) {printf(" READ_\n");}
	  m_cipmachine->READ_(); 
	}
	
	/** 
	 *  Sends the auto event to the cip system.
	 */
	void sendAutoEvent()
	{
	  if (g_eTraceMode == eTrace_Enable) {printf(" AUTO_\n");}
	  m_cipmachine->AUTO_(); 
	}


	/** Forward TestCase SimpleMachineProcessTest */
	int testCase_SimpleMachineProcessTest(int mainTestCase);
	
	/** Forward TestCase ComplexMachineProcessTest */
	int testCase_ComplexMachineProcessTest(int mainTestCase);
	
	/** 
	 *  TestCase SimpleMachineProcessTest
	 *  mainTestCase 1 if main test case, 0 if sub test case.
	 *  @return 1 if test case ok. 0 if test case failed.
	 */
	int testCase_SimpleMachineProcessTest(int mainTestCase)
	{
	  T_UEventData data;
	  T_RecordedActionMessage sRecorded;
	  
	  if (mainTestCase) 
	  {
	    printf(">>> TestCase SimpleMachineProcessTest [f0198f9c-9ac0-11ef-9dfa-835f60e5a95d]\n");
	    s_nSystemTick = 0;
	    g_nRecordedActionMessageCount = 0;
	    g_nExpectedActionMessageCount = 0;
	    if (!fINIT_Machine()) 
	    {
	      printf("\nInitialization failed\n"); 
	      return 0;
	    }
	  }
	  
	  activeTestCase = eTestCase_SimpleMachineProcessTest;
	  sendMessageEvent(eEventMessage_Event_1_powerOn, 50, 50, &data);
	  if (!assertMessageActionCount("TestEvent Event_1.powerOn [f0198f9b-9ac0-11ef-9dfa-835f60e5a95d]", "SimpleMachineProcessTest")) {return 0;}
	  
	  sendMessageEvent(eEventMessage_Event_1_doMachineStuff, 50, 50, &data);
	  if (!assertMessageActionCount("TestEvent Event_1.doMachineStuff [018a8f43-9ac4-11ef-9dfa-835f60e5a95d]", "SimpleMachineProcessTest")) {return 0;}
	  
	  sendMessageEvent(eEventMessage_Event_1_nextWorkload, 50, 50, &data);
	  if (!assertMessageActionCount("TestEvent Event_1.nextWorkload [2051e4e5-9ac4-11ef-9dfa-835f60e5a95d]", "SimpleMachineProcessTest")) {return 0;}
	  
	  sendMessageEvent(eEventMessage_Event_1_powerFail, 50, 50, &data);
	  if (!assertMessageActionCount("TestEvent Event_1.powerFail [3256c6b6-9ac4-11ef-9dfa-835f60e5a95d]", "SimpleMachineProcessTest")) {return 0;}
	  
	  sendMessageEvent(eEventMessage_Event_1_powerOn, 50, 50, &data);
	  if (!assertMessageActionCount("TestEvent Event_1.powerOn [404c14bc-9ac4-11ef-9dfa-835f60e5a95d]", "SimpleMachineProcessTest")) {return 0;}
	  
	 
	  if (mainTestCase) 
	  {
	  	delete m_cipmachine;
	  	m_cipmachine = NULL;
	  }
	  return 1;
	}
	
	/** 
	 *  TestCase ComplexMachineProcessTest
	 *  mainTestCase 1 if main test case, 0 if sub test case.
	 *  @return 1 if test case ok. 0 if test case failed.
	 */
	int testCase_ComplexMachineProcessTest(int mainTestCase)
	{
	  T_UEventData data;
	  T_RecordedActionMessage sRecorded;
	  
	  if (mainTestCase) 
	  {
	    printf(">>> TestCase ComplexMachineProcessTest [7d4d44d8-9ac7-11ef-9dfa-835f60e5a95d]\n");
	    s_nSystemTick = 0;
	    g_nRecordedActionMessageCount = 0;
	    g_nExpectedActionMessageCount = 0;
	    if (!fINIT_Machine()) 
	    {
	      printf("\nInitialization failed\n"); 
	      return 0;
	    }
	  }
	  
	  activeTestCase = eTestCase_ComplexMachineProcessTest;
	  sendMessageEvent(eEventMessage_Event_2_powerOn, 50, 50, &data);
	  if (!assertMessageActionCount("TestEvent Event_2.powerOn [7d4d44da-9ac7-11ef-9dfa-835f60e5a95d]", "ComplexMachineProcessTest")) {return 0;}
	  
	  sendMessageEvent(eEventMessage_Event_2_doMachineStuff, 50, 50, &data);
	  if (!assertMessageActionCount("TestEvent Event_2.doMachineStuff [7d4d44dc-9ac7-11ef-9dfa-835f60e5a95d]", "ComplexMachineProcessTest")) {return 0;}
	  
	  sendMessageEvent(eEventMessage_Event_2_nextWorkload, 50, 50, &data);
	  if (!assertMessageActionCount("TestEvent Event_2.nextWorkload [7d4d44de-9ac7-11ef-9dfa-835f60e5a95d]", "ComplexMachineProcessTest")) {return 0;}
	  
	  sendMessageEvent(eEventMessage_Event_2_powerFail, 50, 50, &data);
	  if (!assertMessageActionCount("TestEvent Event_2.powerFail [7d4d44e0-9ac7-11ef-9dfa-835f60e5a95d]", "ComplexMachineProcessTest")) {return 0;}
	  
	  sendMessageEvent(eEventMessage_Event_2_powerOn, 50, 50, &data);
	  if (!assertMessageActionCount("TestEvent Event_2.powerOn [7d4d44e2-9ac7-11ef-9dfa-835f60e5a95d]", "ComplexMachineProcessTest")) {return 0;}
	  
	 
	  if (mainTestCase) 
	  {
	  	delete m_cipmachine;
	  	m_cipmachine = NULL;
	  }
	  return 1;
	}
	
	/** 
	 *  Regressive animation, controlled by test cases. 
	 *  @return The number of failed test cases.
	 */
	int regressiveAnimation()
	{
	  printf("TESTING: CipTestSuite HistorystateSystemTestSuite [f0198f98-9ac0-11ef-9dfa-835f60e5a95d]\n\n"); 
	  g_eAnimationMode = eAnimationMode_Regressive;
	  int nSuceededTestCases = 0;
	  int nFailedTestCases = 0;
	  g_eTraceMode = eTrace_Enable;
	  if (testCase_SimpleMachineProcessTest(1)) {++nSuceededTestCases;} else {++nFailedTestCases;}
	  g_eTraceMode = eTrace_Enable;
	  if (testCase_ComplexMachineProcessTest(1)) {++nSuceededTestCases;} else {++nFailedTestCases;}
	  printf("\n> SUMMARY: %i Test Case(s) Executed.\n",nSuceededTestCases+nFailedTestCases); 
	  if (nFailedTestCases) {printf("> WARNING: %i Test Case(s) Failed.\n",nFailedTestCases);} 
	  return nFailedTestCases;
	}
	
	/** 
	 *  C/C++ Unit gtest, controlled by test cases. 
	 *  @return The number of failed test cases.
	 */
	int runnerAnimation()
	{
	  int nSuceededTestCases = 0;
	  int nFailedTestCases = 0;
	  g_eAnimationMode = eAnimationMode_Runner;
	  
	  cout << "[==========] Running 2 test from 1 test case." << endl;
	  cout << "[----------] Global test environment set-up." << endl;
	  cout << "[----------] 2 test from HistorystateSystemTestSuite" << endl;
       	  
	  /* SimpleMachineProcessTest */
	  g_eTraceMode = eTrace_Enable;
	  cout << "[ RUN      ] HistorystateSystemTestSuite.SimpleMachineProcessTest" << endl;
	  if (testCase_SimpleMachineProcessTest(1)) {
	  	printf("[       OK ] HistorystateSystemTestSuite.SimpleMachineProcessTest (%i ms)\n",s_nSystemTick);
	  	++nSuceededTestCases;
	  } else {
	  	++nFailedTestCases;
		printf("[  FAILED  ] HistorystateSystemTestSuite.SimpleMachineProcessTest (%i ms)\n",s_nSystemTick);
	  }
	
	  /* ComplexMachineProcessTest */
	  g_eTraceMode = eTrace_Enable;
	  cout << "[ RUN      ] HistorystateSystemTestSuite.ComplexMachineProcessTest" << endl;
	  if (testCase_ComplexMachineProcessTest(1)) {
	  	printf("[       OK ] HistorystateSystemTestSuite.ComplexMachineProcessTest (%i ms)\n",s_nSystemTick);
	  	++nSuceededTestCases;
	  } else {
	  	++nFailedTestCases;
		printf("[  FAILED  ] HistorystateSystemTestSuite.ComplexMachineProcessTest (%i ms)\n",s_nSystemTick);
	  }
	
	  cout << "[----------] 2 test from HistorystateSystemTestSuite (0 ms total)" << endl;
	  printf("\n> SUMMARY: %i Test Case(s) Executed.\n",nSuceededTestCases+nFailedTestCases); 
	  if (nFailedTestCases) {
	  	printf("> WARNING: %i Test Case(s) Failed.\n",nFailedTestCases);
	  }
	  cout << "[----------] Global test environment tear-down" << endl;
	  cout << "[==========] 2 test from 1 test case ran. (0 ms total)" << endl;
	  return nFailedTestCases;
	}
	
	/** 
	 *  Manual animation, controlled by keyboard input. 
	 *  @return 0 if exited normally. 1 otherwise.
	 */
	int manualAnimation()
	{
	  T_UEventData data;
	  g_eAnimationMode = eAnimationMode_Manual;
	  g_eTraceMode = eTrace_Enable;
	  
	  if (!fINIT_Machine()) 
	  {
	    printf("\nInitialization failed\n");
	    return 1;
	  }
	  
	  while (1) 
	  {
	    printf("------------------------------------\n");
	    printf("Enter -1 (Quit)\n");
	    printf("Enter 0 (TICK_ & TIMEUP_)\n");
	    printf("Enter 1 (Step)\n");
	    printf("Enter 2 (TimeUp)\n");
	    printf("Enter 3 (Chain)\n");
	    printf("Enter 4 (Read)\n");
	    printf("Enter 5 (Auto)\n");
	    printf("Enter  %i (Event_1: powerOn)\n",eEventMessage_Event_1_powerOn);
	    printf("Enter  %i (Event_1: powerOff)\n",eEventMessage_Event_1_powerOff);
	    printf("Enter  %i (Event_1: doMachineStuff)\n",eEventMessage_Event_1_doMachineStuff);
	    printf("Enter  %i (Event_1: nextWorkload)\n",eEventMessage_Event_1_nextWorkload);
	    printf("Enter  %i (Event_1: powerFail)\n",eEventMessage_Event_1_powerFail);
	    printf("Enter  %i (Event_2: powerOn)\n",eEventMessage_Event_2_powerOn);
	    printf("Enter  %i (Event_2: powerOff)\n",eEventMessage_Event_2_powerOff);
	    printf("Enter  %i (Event_2: doMachineStuff)\n",eEventMessage_Event_2_doMachineStuff);
	    printf("Enter  %i (Event_2: nextWorkload)\n",eEventMessage_Event_2_nextWorkload);
	    printf("Enter  %i (Event_2: powerFail)\n",eEventMessage_Event_2_powerFail);
	    printf("------------------------------------\n");
	
	    T_EEventMessage eEventMessage;
	    scanf("%i", (int*)&eEventMessage);
	    if (eEventMessage == eEventMessage_Quit) {break;}
	    else if (eEventMessage == eEventMessage_Tick) {
	      data.tick = 1;
	      sendMessageEvent(eEventMessage_Tick, 50, 50, &data);
	    }
	    else if (!sendMessageEvent(eEventMessage, 50, 50, &data)) {printf("\n Invalid Input: %i\n\n",eEventMessage);}
	  }
	  delete m_cipmachine;
	  m_cipmachine = NULL;
	  return 0;
	}
	

	/** 
	 *  Displays an info text for this program.
	 *  @param i_pcProgramName The name of the program file.
	 */
	void displayInfoText(char* i_pcProgramName)
	{
	  printf("Usage: %s [option]\n",i_pcProgramName);
	  printf(" [option]\n");
	  printf(" - manual:     Manual animation, controlled by keyboard input.\n");
	  printf(" - regressive: Regressive animation, controlled by test cases.\n");
	  printf(" - runner: C/C++ Unit gtest.\n");
	}
	
}

/**
 *  Main program for animation.
 *  @param @argc The number of arguments passed to the program.
 *  @param @argv The arguments passed to the program.
 *  @return 0 if exited normally. 1 otherwise.
 */
int main(int argc, char *argv[])
{
	int ret;
	if (argc == 1) 
	{
		dec::displayInfoText(argv[0]);
		return 1;
	}
	
	if (strcmp(argv[1],"manual")==0) 
	{
		ret = dec::manualAnimation()?1:0;
		return ret;
	}
	if (strcmp(argv[1],"regressive")==0) 
	{
		ret = dec::regressiveAnimation()?1:0;
		return ret;
	}
	if (strcmp(argv[1],"runner")==0) 
	{
		ret = dec::runnerAnimation()?1:0;
		return ret;
	}
	dec::displayInfoText(argv[0]);
	return 1;
}

/* Actifsource ID=[167cfacc-121b-11e3-aaf3-772f794ef5e4,f0198f98-9ac0-11ef-9dfa-835f60e5a95d,MsWHdzQDqztggRfMRq2fd4nCpRI=] */
