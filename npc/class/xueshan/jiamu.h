//jiamu.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_jiamu);

virtual void create()
{
	   set_name("��ľ���", "jiamu huofo");
        set("long","��ľ�����ѩɽ���е��ĸ�ɮ���Է��о�����о�������һ����ɫ���ģ�ͷ��ɮñ��Ŀ����磬�ƺ���������");
        set("title","���");
        set("gender", "����");
        set("age", 45);
	set("icon",young_man2);
	set("foolid",158);        
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_hp", 9000);
        set("mp", 3000);
        set("max_mp", 3000);
        set("mp_force", 50);
        set("combat_exp", 1200000);
        set("score", 100000);

        set_skill("mizong_xinfa", 220);
        set_skill("literate", 180);
        set_skill("force", 220);
        set_skill("xiaowuxiang", 210);
        set_skill("dodge", 230);
        set_skill("shenkong_xing", 220);
        set_skill("unarmed", 220);
        set_skill("yujiamu_quan", 180);
        set_skill("parry", 220);
        set_skill("sword", 230);
        set_skill("mingwang_jian", 240);


        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong_xing");
        map_skill("unarmed", "yujiamu_quan");
        map_skill("parry", "riyue_lun");
        map_skill("sword", "mingwang_jian");

        create_family("ѩɽ��", 3, "���");
        set("class", "bonze");

        carry_object("changjian")->wield();
        carry_object("y_jiasha")->wear();
        carry_object("sengmao")->wear();

        add_money(5000);
}

virtual void attempt_apprentice(CChar * player)
{
		char msg[40];

 		  if (DIFFERSTR(player->querystr("gender"), "����"))
		  {
        		say(" ��ϰ�����ڹ���Ҫ����֮�塣",player);
                say(" ��λʩ��������ذɣ�",player);
                SendMenu(player);
                return;
		  }

		  if (DIFFERSTR(player->querystr("class"), "bonze"))
		  {
        	    say(" �ҷ��ŵ����������ࡣ",player);
                say(" ��λʩ��������ذɣ�",player);
                SendMenu(player);
                return;
		  }

        if (DIFFERSTR(player->querystr("family/family_name"), "ѩɽ��"))
        {
                say(" ��λʩ���ȷǱ��µ��ӣ�������ذɣ�",player);
                SendMenu(player);
                return;
		}

        if (player->query_skill("mizong-xinfa", 1) < 60) 
		{
                say(" ����ѩɽ�£���ϰ�����ķ�����Ҫ�ġ�",player);
                say(" ��λʩ���Ƿ�Ӧ�ö�����б��ŵ��ķ���",player);
                SendMenu(player);
                return;
        }
		g_Channel.do_emote(this, player, "smile", 0);
		g_Channel.do_emote(this, player, "nod", 0);

		say("�������ѧϰ�𷨰ɣ�",player);
		SendMenu(player);

		command(snprintf(msg,40,"recruit %ld",player->object_id()) );

		player->set("title","������");
		player->UpdateMe();
}

NPC_END;