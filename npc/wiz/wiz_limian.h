// wiz_limian.h

//code by qinbo
//date:2001-12-31

NPC_BEGIN(CNwiz_limian);

virtual void create()
{
	set_name("����",  "li mian");
	set("title", "����ʹ��һ");
	set("long", "������ȥһ���������ȣ��ɷ���ǣ���ֹ������������ֵ������ı����ƺ�����һ���ŹֵĻ�������ͣ��ð��һ����ֽ�� ");
	set("gender", "����");
	
	set("age", 400);
	set("str", 100);
	set("con", 100);
	set("dex", 100);
	set("int", 100);
	set("icon", pub_boss);
	
	set("combat_exp", 8000000);
	set("attitude", "friendly");
	
	set_inquiry("��������֮һ", ask_for_present);
	
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
	
	me->command(snprintf(msg, 255, "say %ld ��ϲ��������������˳�ġ��������⣡", param1));
}

static char * ask_for_present(CNpc * npc, CChar * who)
{
	char msg[255];
	static char book[65][20] = {
		"kuihua","jiuyang2","jiuyang3","jiuyang4","jiuyang1",
			"yijing1","yijing3","yijing0","yijing2","dujing_1",
			"dujing_2","lbook2","pixie_sword_book","bojuan","book_silk","laozi8",
			"laozi2","laozi18","laozi16","laozi13","laozi1","daodejing_i",
			"daodejing_ii","zhangfapu","blade_book","sword_book1","sword_book2","qinpu",
			"jinyantu","zixia_book","six_book","liumai_sword","literateb4","mizong_book",
			"miaoshou","hand_book","lbook3","dodgebook","quanpu","lbook1",
			"shoufa","18muou","18niou","book_stone","force_book","liuyang_book1",
			"liuyang_book2","throw_book","zhemei_book1","zhemei_book2","qijianpu","book_iron",
			"xisuijing","xuanfeng_book","zhifapu","sun_book","yijinjing","book_paper",
			"yunv_swordb","yunvjing1","yunvjing2","strike_book","staff_book","parry_book",
			"zhengqi_book"
	};
	
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
	
	if(EQUALSTR(who->querystr("liwu_book0404"), "havedone"))
		return "��˵�Ǵ����ģ�������Ҫ���ŵ�����ӣ���Ͳ�Ҫ�����ˡ�";

	CRoom * room = CRresident::get_my_house(who);
	if(!room)
		return "�������Ҷ�û�У���������Ʒ��ʧ��";

	if(who->query("��"))
		return "��Ҫ��Ϊ�����ķ����Ҳ�֪����������";	

	CContainer * ob = load_item(book[random(65)]);
	
	ob->move(who);
	who->set("liwu_book0404", "havedone");
	
	message_vision(snprintf(msg, 255, "$n˵������ʦ������������һ̨��GAMEKING����ӡˢ�������������ڽ��������С�\nֻ�����ڻ���֪������ֶ���ӡ�������������������͸���һ���ڲ��������е���ȥ������\nף�����µ�һ���￪����Զ��\n$n��$N����1��%s��",  ob->name()), who, npc);
	return 0;
}

NPC_END;




