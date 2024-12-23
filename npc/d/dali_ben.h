//dali_ben.h
//天龙本。。
//Lanwood 2000-07-19

#define DALIBEN_BEGIN(npc_name) class npc_name : public CNdali_ben	{	public:	npc_name(){};	virtual ~npc_name(){};
#define DALIBEN_END		};	

NPC_BEGIN(CNdali_ben);

void attack(CChar *me)
{
	CChar::attack(me);

	if(EQUALSTR(environment()->querystr("name"), "六脉剑阵"))
	{
		call_out(do_leave, 1);	
		me->add_temp("beat_count", 1);
	}
}

static void do_leave(CContainer * ob, LONG param1, LONG param2)
{
	//在十八罗汉阵里发过一招后离开。
	CChar * me = (CChar *)ob;
	CContainer * env = me->environment();

	if(! me->is_fighting()) return;

	if(env->Query(IS_FIGHTROOM))
	{
		((CFightRoom * )env)->Leave_Team(me);
		message_vision("$N跳出阵外。", me);		
	}
}

NPC_END;
