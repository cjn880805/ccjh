//lingzhi.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_lingzhi);

virtual void create()
{
	   set_name("��֥����", "lingzhi shangren");
        set("long","��֥������ѩɽ���е�λ�ϸߵ������һ����ɫ���ģ�ͷ��ɮñ��");
        //set("nickname","����");
        set("title", "������" );
        set("gender", "����");
        set("age", 40);
	set("icon",young_man6);
	set("foolid",155);        
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 25);
        set("int", 27);
        set("con", 28);
        set("dex", 26);
        set("max_hp", 4500);
        set("mp", 1500);
        set("max_mp", 1500);
        set("mp_force", 20);
        set("combat_exp", 500000);
        set("score", 80000);

        set_skill("mizong_xinfa", 60);
        set_skill("literate", 60);
        set_skill("force", 100);
        set_skill("xiaowuxiang", 100);
        set_skill("dodge", 100);
        set_skill("shenkong_xing", 80);
        set_skill("parry", 80);
        set_skill("staff", 60);
        set_skill("xiangmo_chu", 80 );
        set_skill("hammer",50);
        set_skill("riyue_lun",50);
        set_skill("unarmed", 110);
        set_skill("yujiamu_quan", 100);


        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong_xing");
        map_skill("unarmed", "yujiamu_quan");
        map_skill("parry", "yujiamu_quan");
        map_skill("staff", "xiangmo_chu");
        map_skill("hammer", "riyue_lun");

        create_family("ѩɽ��", 4, "������");
        set("class", "bonze");

        carry_object("c_jiasha")->wear();
        carry_object("sengmao")->wear();

        add_money(1000);

}

virtual void attempt_apprentice(CChar * player)
{
		char msg[40];

        if (DIFFERSTR(player->querystr("gender"), "����"))
		{
                say("��ϰ�����ڹ���Ҫ����֮�塣",player);
                say("��λʩ��������ذɣ�",player);
                SendMenu(player);
                return;
        }

        if (DIFFERSTR(player->querystr("class"), "bonze"))
		{
                say(" �ҷ��ŵ����������ࡣ",player);
                say(" ��λʩ�����ǻذɣ�",player);
                SendMenu(player);
                return;
        }

        if (DIFFERSTR(player->querystr("family/family_name"), "ѩɽ��"))   
		{
                say(" ��λʩ���ȷǱ��µ��ӣ�������ذɣ�",player);
                SendMenu(player);
                return;
        }

        if (player->query_skill("mizong_xinfa", 1) < 40) 
		{
                say(" ����ѩɽ�£���ϰ�����ķ�����Ҫ�ġ�",player);
                say(" �㻹Ӧ�ö�����б��ŵ��ķ�",player);
                SendMenu(player);
                return;
        }

		g_Channel.do_emote(this,player, "smile", 0);
		g_Channel.do_emote(this,player, "nod", 0);

        say(" �ʹ���һЩ�书�ɣ�",player);
        SendMenu(player);
        command(snprintf(msg, 40,"recruit %ld",player->object_id()) );

        player->set("title", "����");
		player->UpdateMe();
}


NPC_END;