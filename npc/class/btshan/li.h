//li.h
//Lanwood 2000-01-05

NPC_BEGIN(CNbtshan_li);

virtual void create()
{
	set_name("���ͷ",  "li" );
	set("gender", "����" );
	set("age", 25);
	set("long", "���Ǹ��Ͱ����׵Ľ�ͷ��");
	set("attitude", "friendly");
	set("shen_type", -1);
	set("icon", young_man4);

	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
        set_inquiry("����ׯ��","��ׯ����ǰ������ô�ã���Ȼ�����ڱ�������ӣ������һ��ǻ����Ϊ�������յ��书��Ŭ��");
        set_inquiry("����","��������ϣ��书����ȫ��������Ҳ����Ҫ");
	set("max_hp", 1200);
	set("mp", 300);
	set("max_mp", 300);
	set("combat_exp", 250000);
	set("score", 20000);

	set_skill("force", 80);
	set_skill("dodge", 90);
	set_skill("unarmed", 90);
	set_skill("parry", 80);
	set_skill("staff",80);

	set_skill("xunshou_shu", 40);
	
	set_skill("hamagong",70);
	set_skill("chanchu_bufa", 80);
	set_skill("lingshe_zhangfa", 80);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	
	map_skill("parry", "lingshe_zhangfa");
	map_skill("staff", "lingshe_zhangfa");

	create_family("����ɽ��",2,"����");

	set("chat_chance", 2);
			
};

virtual char * chat_msg()
{
	switch(random(3))
	{
	case 0:
		return "���ͷ˵��: ��ѧ�������ɳ���..";
	case 1:
		return "���ͷ����С�����ǲ�η��࣬�ú�������";
	case 2:
		return "���ͷ����ѧͽ��ͷ˵�������ģ�";
	}
	return 0;
}

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && !is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(!who) return;

	if (EQUALSTR(who->querystr("family/family_name"), "����ɽ��"))
	{
	    message_vision("���ͷ����$N���ͷ��΢΢Ц��Ц��", who);
        return;
	}
	
	if (! who->querymap("family"))
	{
	    message_vision("���ͷ����$N΢Ц˵����������ʦ�İɣ����Ұɡ�", who);
	    return;
	}
	
	message_vision("���ͷ��$N�µ�:С�һ�,��Ϲ��ʲô��?", who);
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	say("�ðɣ��������㡣");
    command(snprintf(msg, 80, "recruit %ld", me->object_id()));
    if(me->query_combat_exp() < 10000)
		say("���ȵ�����������������ͯ�ӱȻ����аɡ�");

    return;
}

NPC_END;
