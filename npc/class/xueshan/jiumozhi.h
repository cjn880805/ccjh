//jiumozhi.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_jiumozhi);

virtual void create()
{
	   set_name("�Ħ��", "jiumo xiang");
        set("nickname",  "��������" );
        set("long","������ѩɽ�µ����ţ��˳ƴ����������Ħ�㡣���Է��о�����о�����һ��������ģ�ͷ��ɮñ��");
        set("title","ѩɽ������");
        set("gender", "����");
        set("age", 60);
	set("icon",young_man3);
	set("foolid",160);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 35);
        set("int", 40);
        set("con", 35);
        set("dex", 30);
        set("max_hp", 15000);
        set("mp", 6000);
        set("max_mp", 6000);
        set("mp_force", 150);
        set("combat_exp", 3500000);
        set("score", 700000);

        set_skill("force", 350);
        set_skill("xiaowuxiang", 350);
        set_skill("dodge", 300);
        set_skill("shenkong_xing", 300);
        set_skill("unarmed", 300);
        set_skill("yujiamu_quan", 300);
        set_skill("parry", 300);
        set_skill("sword", 300);
        set_skill("mingwang_jian", 300);
        set_skill("mizong_xinfa", 300);
        set_skill("literate", 300);
        set_skill("staff", 300);
        set_skill("xiangmo_chu", 300 );
        set_skill("strike", 300 );
        set_skill("huoyan_dao", 300);



        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong_xing");
        map_skill("unarmed", "yujiamu_quan");
        map_skill("parry", "mingwang_jian");
        map_skill("sword", "mingwang_jian");
        map_skill("staff", "xiangmo_chu");
        map_skill("strike","huoyan_dao");

        create_family("ѩɽ��", 1, "����");
        set("class", "bonze");

        carry_object("changjian")->wield();
        carry_object("r_jiasha")->wear();
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

        if (player->query_skill("mizong_xinfa", 1) < 100) 
		{
                say(" ����ѩɽ�£���ϰ�����ķ�����Ҫ�ġ�",player);
                say(" ��λʩ���Ƿ�Ӧ�ö�����б��ŵ��ķ���",player);
                SendMenu(player);
                return;
        }

       command(snprintf(msg,40,"recruit %ld",player->object_id()) );

		player->set("title","����");
		player->UpdateMe();
}

NPC_END;