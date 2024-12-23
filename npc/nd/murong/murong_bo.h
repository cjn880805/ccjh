// murongbo.c  Ľ�ݲ�
//sound 2001-07-16

NPC_BEGIN(CNmurong_bo);

virtual void create()
{
	set_name("Ľ��Ԩ��", "murong bo");
	set("title","����Ľ����ү��");
	set("nick","�Ա�֮�� ��ʩ����");
	set("long", 
		"���������ºų��Ա�֮��������֮��Ĺ���Ľ��Ԩ����\n"
		"�����ϴ��Ų���һ����Ц�ݡ�\n");
	set("age", 57);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("icon",old_man1);
	
	set("hp", 4500);
	set("max_hp", 4500);
	set("mp", 4500);
	set("max_mp", 4500);
	set("mp_factor", 200);
	set("combat_exp", 4000000);
	set("score", 50000);                
	set("chat_chance_combat",40);
	
	set_skill("xingyi_zhang",200);
	set_skill("strike",200);
	set_skill("finger",200);
	set_skill("dodge",200);
	set_skill("force", 200);
	set_skill("canhe_zhi", 300);
	set_skill("murong_jianfa",300);       
	set_skill("shenyuan_gong", 300);
	set_skill("yanling_shenfa", 300);
	set_skill("douzhuan_xingyi", 300);
	set_skill("parry", 210);
	set_skill("sword", 200);
	set_skill("literate", 200);
	set_skill("murong_daofa", 300);
	set_skill("blade",200);
	
	map_skill("blade", "murong_daofa");
	map_skill("finger", "canhe_zhi");
	map_skill("force", "shenyuan_gong");
	map_skill("dodge", "yanling_shenfa");
	map_skill("parry", "douzhuan_xingyi");
	map_skill("sword", "murong_jianfa");
	
	prepare_skill("finger","canhe_zhi");
	
	create_family("����Ľ��",1,"����");
	
	set_inquiry("����", "�Ҿ����Ա�֮������ʩ����Ĺ���Ľ��Ԩ����");
	set_inquiry("����", "�����������µĲؾ�¥��");
	set_inquiry("����",  "����Ľ���ظ���������֮�д�������ͷ����ү�����������ѽ��");
	
}

virtual char * chat_msg_combat()
{
//	perform_action("parry xingyi", 1);

	return 0;
}
/*
void attempt_apprentice(object ob)
{
	object me  = this_player();
	
	string name, new_name;
	name = ob->query("name");
	
	if (present("jiaxin", me))
	{  destruct(present("jiaxin",me));
	
	command("say �ðɣ���Ȼ" + RANK_D->query_respect(ob) + "���Ҷ����ż�����Ϊ��" +
		"��������������Ҿ�������ɡ�");
	
	new_name = "Ľ��" + name[2..3];
	ob->set("name", new_name);
	command("say �ӽ��Ժ���ͽ���" + new_name + "��ϣ�����ܰ�Ľ�ݹ�������");
	command("recruit " + ob->query("id"));
	command("chat ����һЦ��˭�� �Ա�֮�� ��ʩ���� ����������");
	command("chat* haha"); 
	}
	else
		command("say ��Ľ�ݲ����������ͽ!");
	return;	   
}
*/
NPC_END;
