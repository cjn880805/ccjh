//longnv.h
//code by zwb
//12-23

NPC_BEGIN(CNxiake_yanruoshui);

virtual void create()
{
		set_name("����ˮ","yan ruoshui");

        set("gender", "����");
        set("age", 28);
        set("long","����������߹���֮һ������ˮ����˫�޶Ե�һ���ˡ�");
        set("title","����ʴ��");
        set("attitude", "friendly");
		set("icon",young_man1);

        set("per", 40);
        set("str", 40);
        set("int", 37);
        set("con", 36);
        set("dex", 58);

		set("chat_chance", 6);
		set("chat_chance_combat", 40);

        set("hp", 20500);
        set("max_hp", 20500);
        set("mp", 5000);
        set("max_mp", 5000);
        set("mp_factor", 400);

        set("combat_exp", 8000000);

        set_skill("force", 400);
        set_skill("xuanwu_douqi", 400);

        set_skill("sword", 370);
        set_skill("misssword",370);
        set_skill("viviensword",370);

        set_skill("blade", 370);
        set_skill("missblade",370);

		set_skill("parry", 360);

        set_skill("literate",360);

        set("rank_info/respect", "�๫��");

        map_skill("force", "xuanwu_douqi");
        map_skill("sword", "misssword");
        map_skill("blade", "missblade");
        map_skill("parry", "viviensword");

        create_family("����ɽׯ", 1, "ׯ��");

//        carry_object("bamboosword")->wield();
		carry_object("mujian")->wield();		//no bamboosword lanwood 2001-03-28
		set("class","traveller");

}

virtual char * chat_msg_combat(CChar * player)
{
//	char msg[255];
	if (!random(10))
	{
		perform_action("force xiruo", 1);
		return 0;
	}
	if (random(2))
		perform_action("force budu", 1);
	else
		perform_action("sword xiangsi", 1);
	return 0;
}

virtual char * chat_msg()
{
	switch(random(4))
	{
	case 0:
		return "����ˮ���ֿ��Ű��ƣ����Ƶ���ɽ���꣬��غϣ�������������ѩ����";
	case 1:
		return "����ˮ����Զ�����δ󺣣�̾�����˼��������˼����";
	case 2:
		return "����ˮͷҲ���أ�����һ������ƽ������ḡ����ô�������������˼�������⣿";
	case 3:
		return "����ˮ̾������ĳ��һ��ƫ�����������Ķ��У����ʵ����Ƕ�����ڣ�ֻ�Ǻ����ˡ���";
	case 4:
		return "����ˮ��ͷ��˼���Σ����о������������";
	}
	return "";
}



virtual void attempt_apprentice(CChar  * ob)
{
	if(current_time - (int) ob->query("last_time_app_master_yan") < 172800)
	{
        message_vision("����ˮЦ��������ô��ô���ֻ����ˣ�����",ob);
        return;
    }

	if(ob->query("mp_factor") < 150)
	{
        message_vision("����ˮЦ��������书���˽⻹����������",ob);
		return;
	}

	if( random(400) || random((ob->query_int()+ob->query_str()+ob->query_dex()+ob->query_con())) >  50 || query("already"))
	{
		message_vision("����ˮ����һЦ�������ҿɲ��������ӵܣ������㻹��ȥ�����������ɡ�",ob);
		ob->set("last_time_app_master_yan",t);
        return;
    }
	message_vision("����ˮ�·��������Լ��ĳ������ˣ������˰��죮����",ob);
    command("sigh");
	message_vision("����ˮ����һЦ������������ˣ��Ҿ�������ɣ�����",ob);
	recruit_apprentice(ob);
	set("already",1);
}

NPC_END;
