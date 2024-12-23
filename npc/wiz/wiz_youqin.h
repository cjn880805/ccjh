//wiz_youqin.h
//muri 2001-11-16

NPC_BEGIN(CNwiz_youqin);

void create()
{
    set_name("����", "zi ying");
	set("title", "�Ʋ����ռ�");
	set("gender", "����" );

	set("age", 400);
	set("str", 100);
	set("con", 100);
	set("dex", 100);
	set("int", 100);
         
	set("long",	"���������ϹĹ����ң���֪���ǲ��ǳ��Ŷ�����ȫ���ļҵ�" );

	set("combat_exp", 8000000);
	set("attitude", "friendly");
	
	set_inquiry("����", ask_for_present),
	
	set_temp("no_kill", 1);
	set("hp", 15000);
	set("max_hp", 15000);
	set("mp", 5000);
	set("max_mp", 5000);
    set("mp_factor", 300);

	set_skill("dodge", 500);
	set_skill("unarmed", 500);
	set_skill("parry", 500);
	set_skill("force",500);
    set_skill("literate",500);
    set_skill("cuff", 500);

    set_skill("qiankun_danuoyi",500);
    set_skill("jingang_quan",500);
    set_skill("hunyuan_yiqi",500);
     
    map_skill("force", "hunyuan_yiqi");
	map_skill("parry", "qiankun_danuoyi");
	map_skill("cuff", "jingang_quan");
    map_skill("dodge", "qiankun_danuoyi");
        
    prepare_skill("cuff", "jingang_quan");

	set_temp("apply/attack", 500);
	set_temp("apply/dodge", 500);
     set("marks", "havedone");
    //carry_object("yuyi")->wear();
}

char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
			perform_action("cuff jingang", 1);
			break;
	case 1:
			perform_action("force recover", 0);
			break;
	case 2:
            perform_action("force powerup", 0);
			break;
	}

	return 0;
}

void init(CChar * me)
{
	CNpc::init(me);

	if( userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}


static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;
	
    me->command(snprintf(msg, 255, "say %ld ����������ʦ��ծ�İɣ�", param1));
}

static char * ask_for_present(CNpc * npc, CChar * who)
{
	char msg[255];
    int i;

     if (who->query("combat_exp") < 3000 || who->query("mud_age") < 18000)
        return "�ٺ٣������������ƭ�ң�û�ţ���";
	
     if (who->query("combat_exp") >=3000 ) 
    {
		CMapping * skl = who->query_skills();
		CVector sname;
		int how = 0;
		
		skl->keys(sname);
		
        for(i=0; i< sname.count(); i++)
            if (skl->query(sname[i]) >= 10) how ++;
			
			if(how < 3)
				return "�����ˮƽ����ȥ��һ�������";
	} 

     if(EQUALSTR(who->querystr("youqin_gift"), npc->querystr("marks")))
		return "�Һ���ģ�������̫��ģ�ÿ����ֻ��һ�ݰɣ�";

     CContainer * ob = load_item("amends");

     ob->move(who);
     who->set("youqin_gift", npc->querystr("marks"));

	 message_vision(snprintf(msg, 255, "$n˵��������������ֿ��Ʋ��ˣ�\n$n��$N����1��%s��",  ob->name()), who, npc);
     return 0;
}

NPC_END;
