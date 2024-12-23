#include "../server/Room.h"
#include "../server/Npc.h"

#define ZUSHI_BEGIN(npc_name)	class npc_name : public CNzushi	{	public:	npc_name(){};	virtual ~npc_name(){};
#define ZUSHI_END		};	

//标准开山祖师
//可授权掌门
//Lanwood 2001-02-03

NPC_BEGIN(CNzushi);

virtual void setup()
{
	CNpc::setup();

	//再此增加询问
	set_inquiry("掌门", ask_zhangmen);	
}

//开除不在线弟子，单方面撕毁合约
int do_expell(CChar * me, char * arg)
{
	//列出可以开除的弟子
	CMapping * ptr = g_Channel.query_recruit(me->id(1));
	char msg[255], cmd[80];

	if(! ptr || ! ptr->GetCount())
		return notify_fail("你还没有收徒经验！");

	if(strlen(arg))
	{
		ptr->del(arg);

		g_Channel.update_recruit(me->id(1), arg, "----", 0, 0);

		say("好的。", me);
		SendMenu(me);
		return 1;
	}

	say("如果弟子不勤奋练功，可向我请求忽略他占有的收徒名额。", me);
	say("但是，他为你贡献的掌门经验也将被扣除，请务必考虑清楚。", me);
	
	CVector v;

	ptr->keys(v);

	for(int i=0; i<v.count(); i++)
	{
		const char * key = v[i];
		CMapping * p = ptr->querymap(key);

		if(! p) continue;

		if(! p->query("apprentice")) continue;

		AddMenuItem(snprintf(msg, 255, "徒弟%s(%s)：%ld",
					p->querystr("name"),
					key, 					
					p->query("exp") / 100	),
			snprintf(cmd, 80, "$0wantexpell $1 %s", key), me);
	}

	SendMenu(me);
	return 1;
}

static char * ask_zhangmen(CNpc * me, CChar * who)
{
	//检查玩家的各项技能
	CMapping * skills = who->query_skills();
	int count = 0;

	if(DIFFERSTR(who->querystr("family/family_name"), me->querystr("family/family_name")))
	{
		return "你是谁？";
	}

	if(who->query("zhangmen"))
	{
		me->say("今后，本派的光复就指望你了！");
		me->AddMenuItem("多谢师父指教！", "", who);
		me->AddMenuItem("我想开除弟子。", "$0wantexpell $1", who);
		me->SendMenu(who);
		return 0;
	}

	if(who->query("recruit_exp"))
	{
		//收满10个徒弟即可挑战掌门之位
		if(who->recruit_num() >= 10)
		{
			who->set_temp("fight_zhangmen", 1);

			me->say("不错！你为光大本门立下汗马功劳，辛苦了！", who);
			me->say("现在就挑战你的师兄赢得掌门之位吧！", who);
			me->SendMenu(who);			
			return 0;
		}

		me->say("要多多提携徒弟，才能增进自己的掌门经验。", who);
		me->say("积累了一定的掌门经验后，才能带更多的徒弟。", who);
		me->say("等你带出十个徒弟后再来申请掌门吧。", who);
		me->AddMenuItem("多谢师父指教！", "", who);
		me->AddMenuItem("我想开除弟子。", "$0wantexpell $1", who);
		me->AddMenuItem("我决定退出申请掌门。", "$0fqzm $1", who);
		me->SendMenu(who);
		return 0;
	}

	CVector v;

	skills->keys(v);

	for(int i=0; i<v.count(); i++)
		if( (* skills)[v[i]] > 150) count ++;

	if(count < 10)
		return "你还没有资格申请掌门。";

	who->set("recruit_exp", 50);
	return "那么就多带带徒弟历练一下吧！";
}
	
int handle_action(char * comm, CChar *me, char * arg)
{
	if(strcmp(comm, "fqzm") == 0)
	{
		say("哎，那太可惜了！", me);
		me->del("recruit_exp");
		SendMenu(me);
		return 1;
	}
	else if(strcmp(comm, "wantexpell") == 0)
		return do_expell(me, arg);

	return CNpc::handle_action(comm, me, arg);
}

NPC_END;