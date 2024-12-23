//lazhang.h
//code by zwb
//1-15
//inherit F_MASTER;

NPC_BEGIN(CNxueshan_lazhang);

virtual void create()
{
	   set_name("���»��", "lazhang huofo");
        set("long","���»����ѩɽ���е��ĸ�ɮ���Է��о�����о��� ����һ����ɫ���ģ�ͷ��ɮñ����ü��Ŀ���ƺ����޸���֮����"); 
        set("title","���"); 
        set("gender", "����"); 
        set("age", 50);
	set("icon",young_man5);
	set("foolid",161);         
        set("attitude", "peaceful"); 
        set("shen_type", -1); 
        set("str", 30); 
        set("int", 30); 
        set("con", 30); 
        set("dex", 30); 
        set("max_hp", 12000); 
        set("mp", 4000); 
        set("max_mp", 4000); 
        set("mp_force", 50); 
        set("combat_exp", 1300000); 
        set("score", 100000); 
 
        set_skill("mizong_xinfa", 230); 
        set_skill("literate", 180); 
        set_skill("force", 180); 
        set_skill("xiaowuxiang", 180); 
        set_skill("dodge", 220); 
        set_skill("shenkong_xing", 210); 
        set_skill("unarmed", 240); 
        set_skill("yujiamu_quan", 240); 
        set_skill("parry", 220); 
        set_skill("sword", 180); 
        set_skill("mingwang_jian", 180); 
 
 
        map_skill("force", "xiaowuxiang"); 
        map_skill("dodge", "shenkong_xing"); 
        map_skill("unarmed", "yujiamu_quan"); 
        map_skill("parry", "riyue_lun"); 
        map_skill("sword", "mingwang_jian"); 
 
 
        create_family("ѩɽ��", 3, "���"); 
        set("class", "bonze"); 

        set_inquiry("���",ask_for_join);
 
        carry_object("y_jiasha")->wear(); 
        carry_object("sengmao")->wear(); 
 
        add_money(5000); 
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
				player->set_temp("pending/join_bonze", 1);
				say("ʩ������������ҷ𣬾�������ܽ�");
				SendMenu(player);
                return;
        }

        if (DIFFERSTR(player->querystr("family/family_name"), "ѩɽ��"))   
		{
                say(" ��λʩ���ȷǱ��µ��ӣ�������ذɣ�",player);
				say(" ��λʩ�������ȸ����ײ�ʦ��ѧϰ��",player);
				SendMenu(player);
                return;
        }

        if (player->query_skill("mizong_xinfa", 1) < 60) 
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

static char * ask_for_join(CNpc * npc , CChar * player)
{
	if(EQUALSTR(player->querystr("class"), "bonze") )
	{
		npc->say(" �����ӷ�����ͬ�ǳ����ˣ��ιʸ�ƶɮ�������Ц��",player);
		npc->SendMenu(player);
		return 0;
	}

    if(DIFFERSTR(player->querystr("gender"), "����") )
	{
		npc->say(" ʩ��������������ǿ�ϲ�ɺأ���ϧ����ֻ����ͽ��",player);
		npc->SendMenu(player);
		return 0;
	}

    player->set_temp("pending/join_bonze", 1);
	npc->say(" �����ӷ����գ����գ�ʩ������������ҷ�������ܽ䡣",player);
	npc->AddMenuItem("�¹�", "kneel", player);
	npc->AddMenuItem("�뿪", "", player);
	npc->SendMenu(player);

	return "";
}

virtual int do_talk(CChar * player , char * ask=NULL)
{
	if(!ask) return 0;

	if(player->query_temp("pending/join_bonze"))
	{
		if(strcmp(ask, "kneel") == 0)
		{
			return do_kneel(player);
		}
		return 1;
	}
	return CNpc::do_talk(player, ask);
}

int do_kneel(CChar * player)
{
    if( !player->query_temp("pending/join_bonze") )
		return 0;

	message_vision("$N˫�ֺ�ʮ�����������ع���������$n˵�ʵ���һ΢�������������ɾ�һ��΢����������΢���಻������һ������˼ɲ������������$N��ͷ�ڷ��������£�ͷ����ͺͺ�ظ���һ��ͷ�����������굶����������ȸɾ���",player, this);

	player->delete_temp("pending/join_bonze");
	player->set("class", "bonze");
    g_Channel.do_emote(this, player, "smile", 0);

	return 1;
}
NPC_END;