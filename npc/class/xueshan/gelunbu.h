//gelunbu.h
//code by zwb
//1_15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_gelunbu);

virtual void create()
{
	   set_name("���ײ�", "inlun fawang");
        set("long","���ײ���ѩɽ���л���ɮ����ͷ�졣ͬʱ���µ��Ӵ����书����һ����ɫ���ģ�ͷ��ɮñ��");
        set("title", "����");
        set("nickname", "ɮ��ͷ��");
        set("gender", "����");
        set("age", 30);
	set("icon",young_man4);
        
	set("foolid",157);        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 30);
        set("int", 20);
        set("con", 28);
        set("dex", 25);

        set("max_hp", 3000);
        set("mp", 1000);
        set("max_mp", 1000);
        set("mp_force", 20);
        set("combat_exp", 200000);
        set("score", 40000);

        set_skill("mizong_xinfa", 40);
        set_skill("literate", 30);
        set_skill("force", 80);
        set_skill("xiaowuxiang", 80);
        set_skill("dodge", 75);
        set_skill("shenkong_xing", 70);
        set_skill("parry", 60);
        set_skill("staff", 80);
        set_skill("xiangmo_chu", 70 );
        set_skill("hammer",50);
        set_skill("riyue_lun",40);
        set_skill("unarmed", 60);
        set_skill("yujiamu_quan", 60);



        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong_xing");
        map_skill("parry", "xiangmo_chu");
        map_skill("staff", "xiangmo_chu");
        map_skill("hammer","riyue_lun");
        map_skill("unarmed","yujiamu_quan");

        create_family("ѩɽ��", 5, "����");
        set("class", "bonze");

        carry_object("b_jiasha")->wear();
        carry_object("sengmao")->wear();
        carry_object("senggun")->wield();

        add_money(3000);
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


		say("�Ҿʹ���һЩ�书�ɣ�");	
		command(snprintf(msg,40,"recruit %ld",player->object_id()) );

        if(DIFFERSTR(player->querystr("class"), "bonze")) 
		{
                player->set("title","�׼ҵ���");
        }
        else 
		{
                player->set("title","С����");
        }

		player->UpdateMe();
}

NPC_END;