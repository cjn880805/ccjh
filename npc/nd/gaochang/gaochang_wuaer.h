// wuaer.c �߶�����
//sound 2001-07-11

NPC_BEGIN(CNgaochang_wuaer);

virtual void create()
{
	set_name("�߶�����", "wuaer laqi");
	set("gender", "����");
	set("age", 45);
	set("icon",young_man6);			//������������
	set("long", "������װ��Ū����߶����롣�����ݿ��£����ڳ��ڲ������⣬Ƥ���Ұס�");
	
	set("combat_exp", 50000);
	set("shen_type", 1);
	
	set("max_mp", 500);
	set("mp", 500);
	set("mp_factor", 10);
	
	set_skill("force", 40);
	set_skill("sword", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	
	set_inquiry("������", "�߶�����˵��������һ���ù����ʱ���ټ�������");
/*	
	set("inquiry", ([
		"����" : (: ask_baozang :),
		"��ȥ" : (: ask_back :),
		"�߶�����" : (: ask_wuaer :),
        ]) );
*/	
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);
	
	carry_object("gangdao")->wield();
//	carry_object("bladebook")->wear();
}
/*
int ask_back()
{    
	object ob;
	object me=this_player();
	if ( present("map", me))
	{
		say("�߶�����˵�����ðɣ�����������ȥ���߲��Թ����Ժ���Ҳ��Ҫ���ˡ�
			�´����Ҿ�Ҫɱ���㡣\n");
			ob->move(__DIR__"entrance");
		return 1;
	}
	else {
		say("�߶�����ߵ��������������ܣ���������һ���Ӱ�!\n");
		return 1;
	}
	return 1;
}

int ask_baozang()
{
	say("�߶�����˵�����߲��Թ�һ�����У���һ����������ס�ġ�
		˵�������ó�һ��·��\n");
}    
int ask_wuaer()
{
	message("vision",
		HIY "�߶����벪Ȼ��ŭ���ȵ�����Ҳ��ֱ���ҵ����֣�����Ҫɱ���㣡\n"
		NOR, environment(), this_object() );
	kill_ob(this_player());
	return 1;
}
*/
NPC_END;