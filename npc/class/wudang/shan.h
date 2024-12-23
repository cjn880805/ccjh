//shan.h
//code by zwb
//12-16

NPC_BEGIN(CNwudang_shan);

virtual void create()
{
	set_name("�Ŵ�ɽ", "zhang cuishan");
	set("long","�������������������ĵ��ӡ��䵱����֮����Ŵ�ɽ����һ���ɸɾ������಼������������ʮ��ͷ��ͣ�����Ӣ����һ������������ͷ��");
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");
	set("class", "scholar");
	set("shen_type", 1);
	set("str", 28);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	set("icon",taoist_with_sword);	
	set("foolid",120);
	set("max_hp", 6000);
	set("mp", 1500);
	set("max_mp", 2000);
	set("mp_force", 50);
	set("combat_exp", 500000);
	set("score", 60000);
	set("chat_chance_combat", 60);
	
	set_skill("force", 100);
	set_skill("taiji_shengong", 100);
	set_skill("dodge", 100);
	set_skill("tiyunzong", 100);
	set_skill("unarmed", 100);
	set_skill("taiji_quan", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("liangyi_jian", 160);
	set_skill("taiji_jian", 100);
	set_skill("literate", 100);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "liangyi_jian");
	map_skill("sword", "liangyi_jian");
	
	create_family("�䵱��", 2, "����");
	
	carry_object("changjian")->wield();
	carry_object("bluecloth")->wear();
}

virtual char * chat_msg_combat()
{
	perform_action("sword ren",1);
	return 0;
}

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		return "�Ŵ�ɽ��ݺݵ�˵����û������ˢ�ӣ��Ҹ����⽣�ң�";
	case 1:
		return "�Ŵ�ɽ����̾�����ĸ���ʦ�����ҵ����أ�����Ѽׯһ�١�";
	}
	return 0;
}
/*
void greeting(object ob)
{
        if ((int)ob->query("shen") < 0)
        {
            say(CYN"\n\n�Ŵ�ɽ����ŭ�ݣ���аħ��������˱��ӵ��ˣ���ǿ���䵱����\n\n");
            message_vision("�Ŵ�ɽ�Ӹ����£�����һ�ƣ�$Nֻ��Ӳ�ӣ����ӻ���һ�¡�\n",ob);
            message_vision("�Է����ֳ����漴�ݳ���$N�޷��мܣ�����һ����\n\n\n"NOR,ob);
            ob->move("/d/wudang/slxl2");
        }
}  */

virtual void attempt_apprentice(CChar * player)
{
		char msg[255];

		//��ʱ��Ҫ��ɽ�ŵ����񡣴˶�ע�͵���lanwood 2001-02-24
		/*
        if (player->query("guarded") < 1) 
	{
			say("������䵱�ɾ��˶����������м��������أ�",player);
			SendMenu(player);
            return;
        }
		*/
        if (player->query_int() < 30)
        {
			say("������ʽ������������������ľ��磬����Ҳ�ǰ״",player);
			SendMenu(player);
            return;
        }
        if (player->query("repute") < 0)
		{
			say(" ���䵱���������������ɣ��Ե���Ҫ���ϡ�",player);
            say(" �ڵ��з��������ò�����",player);
            SendMenu(player);
            return;
        }
        say(" �ðɣ��Ҿ��������ˡ�");
        command(snprintf(msg,255,"recruit %ld",player->object_id()));
}

NPC_END;