//feng.h
//Lanwood 2000-01-08

NPC_BEGIN(CNhuashan_feng);

virtual void create()
{
	set_name("风轻扬", "feng qingyang");

	set("long", "他就是华山剑宗的长老风轻扬。他身材瘦长，眉宇间一直笼罩着一股淡淡的忧伤");

	set("gender", "男性");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 35);
	set("dex", 35);
	set("icon",old_man2);
	
	set("hp", 30500);
	set("max_hp", 30500);
	
	set("mp", 18500);
	set("max_mp", 18500);
	set("mp_factor", 200);

	set("combat_exp", 70000000);
	set("score", 500000);

	set_skill("cuff", 250);
	set_skill("force", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("sword", 400);
	set_skill("strike",250);
	set_skill("unarmed", 250);
	set_skill("zixia_shengong", 250);
	set_skill("poyu_quan", 250);
	set_skill("huashan_sword", 300);
	set_skill("hunyuan_zhang", 250);
	set_skill("lonely_sword", 300);
	set_skill("huashan_shenfa",250);
	set_skill("literate", 220);
	set_skill("zhengqijue", 250);

	map_skill("cuff", "poyu_quan");
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "huashan_shenfa");
	map_skill("parry", "lonely_sword");
	map_skill("sword", "lonely_sword");
	map_skill("strike", "hunyuan_zhang");

	create_family("华山派", 12, "弟子");

	set("chat_chance_combat", 60);
	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();

	set("no_get", 1);
	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);
	set("shen_type", 1);

	//reset();
	set("file_name", querystr("base_name"));
	Load();
	call_out(do_reset, 1);
};

int Save()
{
	char msg[255];
	return SaveToLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);
}

int Load()
{
	char msg[255];
	return LoadFromLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);	
}

static void do_reset(CContainer * ob, LONG param1, LONG param2)
//void reset()
{
	CChar * npc = (CChar *)ob;
	int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	//检查系统时间
	time_t t;	
	struct tm * newtime;

	time(&t);
	newtime = localtime(&t); 
	
	//月底，最后一天。
	if(newtime->tm_mday != mdays[newtime->tm_mon]) 
	{
		npc->call_out(do_reset, 3600);
		return;
	}
	//最后一小时
	if(newtime->tm_hour != 23) 
	{
		npc->call_out(do_reset, 3600);
		return;
	}
	if(npc->query("month")==newtime->tm_mon)
	{
		npc->call_out(do_reset, 3600);
		return;
	}
	int passtime = newtime->tm_min * 60 + newtime->tm_sec;	//已经过去的秒

	npc->set_temp("month",newtime->tm_mon);
	//remove_call_out(do_renew);
	npc->call_out(do_renew, 3600 - passtime);	
}

static void do_renew(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	npc->set("month",npc->query_temp("month"));
	npc->delete_temp("month");
	npc->del("徒弟");
	npc->Save();
	//remove("data/npc/FENG");
}

char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("sword poqi", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}
	
	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];
/*	int student_num = 0;
	
	FILE * fp;
	
	if((fp = fopen("data/npc/FENG", "rb")))
	{
		fread(&student_num, sizeof(int), 1, fp);
		fclose(fp);
	}
*/
	if(query("徒弟"))
		say(snprintf(msg, 255, "“我现在共有%ld个徒弟。”", query("徒弟")), me);
	
	if (query("徒弟") == 3)
	{
		say("你来晚了，我已经收了三个徒弟了。", me);
		SendMenu(me);
		return;
	}

	if ( me->querymap("family") &&
	     DIFFERSTR(me->querystr("family/family_name"), "华山派"))
	{
		say(snprintf(msg, 255, "%s既然已有名师指点，何必又来拜老朽呢？", query_respect(me)), me);
		SendMenu(me);
		return;
	}

	if ((me->query_skill("sword",1) < 150) || (me->query_skill("huashan_sword",1) < 150))
	{
		say(snprintf(msg, 255, "我看%s的华山剑法还没学到家吧。", query_respect(me)), me);
		SendMenu(me);
		return;
	}

	if ((me->query_skill("force",1) < 150) || (me->query_skill("zixia_shengong",1) < 130))
	{
		say(snprintf(msg, 255, "我看%s的紫霞神功还没学到家吧。", query_respect(me)), me);
		SendMenu(me);
		return;
	}

	if ((me->query_skill("dodge",1) < 150) || (me->query_skill("huashan_shenfa",1) < 150))
	{
		say(snprintf(msg, 255, "我看%s的华山身法还没学到家吧。", query_respect(me)), me);
		SendMenu(me);
		return;
	}

	if ( me->query_skill("literate",1) < 160)
	{
		say(snprintf(msg, 255, "我看%s的读书识字还没学到家吧。", query_respect(me)), me);
		SendMenu(me);
		return;
	}

	if (me->query("repute") < 100000)
	{
		say("我华山派乃是堂堂名门正派，对弟子要求极严。", me);
		say(snprintf(msg, 255, "在德行方面，%s是否还做得不够？", query_respect(me)), me);
		SendMenu(me);
		return;
	}

	if (me->query_int() < 41) 
	{
		say(snprintf(msg, 255, "依我看%s的资质似乎不适合学我独孤九剑？", query_respect(me)), me);
		SendMenu(me);
		return;
	}

	say("好吧，我就收下你了。", me);
	SendMenu(me);

	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	me->set("class", "swordsman");
	me->UpdateMe();
	add("徒弟",1);
	Save();
	/*
	student_num++;

	if((fp = fopen("data/npc/FENG", "wb")))
	{
		fwrite(&student_num, sizeof(int), 1, fp);
		fclose(fp);
	}
*/
}

NPC_END;
