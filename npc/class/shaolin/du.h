//du.h
//少林渡字辈
//Lanwood 2000-01-09

#define SHAOLINDU_BEGIN(npc_name) class npc_name : public CNshaolin_du	{	public:	npc_name(){};	virtual ~npc_name(){};
#define SHAOLINDU_END		};	

NPC_BEGIN(CNshaolin_du);

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];

	if ( me->query("betrayer") >= 2)
	{
		say("你叛师次数太多了，我不能收你。", me);
		SendMenu(me);
		return;
	}

	if (DIFFERSTR(me->querystr("family/family_name"), "少林派"))
	{
		say("你与本派素无来往，不知此话从何谈起？", me);
		SendMenu(me);
		return;
	}

	if ( DIFFERSTR(me->querystr("class"), "bonze") && EQUALSTR(me->querystr("family/family_name"), "少林派")) 
	{
		say("你是俗家弟子，不能在寺内学艺。", me);
		SendMenu(me);
		return;
	}

	if ( me->query("family/generation") <= query("family/generation") )
	{
		say("这，贫僧哪里敢当 !", me);
		SendMenu(me);
		return;
	}

	if ( me->query("family/generation") == query("family/generation") + 1) 
	{
		say(snprintf(msg, 255, "%s的徒弟怎麽跑到我这儿来了，哈哈哈 !", me->querystr("family/master_name")));
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	}

	if (me->query("family/generation") == 37)
	{
		if (me->query_skill("dodge", 1) < 120 ||
		    me->query_skill("parry", 1) < 120 ||
		    me->query_skill("force", 1) < 120 ||
		    me->query_skill("buddhism", 1) < 120 ||
		    me->query_skill("hunyuan_yiqi", 1) < 120 ||
		    me->query_skill("shaolin_shenfa", 1) < 120) {
			say("你是否还应该在各项技能上多下点功夫？", me);
			SendMenu(me);
			return;
		}

		command("chat 0 哈哈哈哈！！！！");
		command("chat 0 想不到老纳在垂死之年，又觅得一个可塑之才，真是可喜可贺。");
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	
		say(snprintf(msg, 255, "是%s叫你来找我的吧，哈哈哈 !", me->querystr("family/master_name")));
		say("贫僧又得一可塑之才，真是可喜可贺 !", me);

		char new_name[5], myname[5];
		strncpy(myname, me->name(), 4)[4] = 0;
		strcpy(new_name, "玄");
		new_name[2] = myname[2];
		new_name[3] = myname[3];
		new_name[4] = 0;

		me->set_name( new_name);
		me->set("family/generation", 36);

		say(snprintf(msg, 255, "从今以后你的法名叫做%s，恭喜你荣升为少林派玄字辈弟子 !", new_name));
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));		
	}
}


NPC_END;
