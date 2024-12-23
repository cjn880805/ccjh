//chongtian ���� 
//�����ڰ˲�BOSS

BOSS_BEGIN(CNchongtian);

virtual void create()
{	
	set_name("����", "chong tian");
	set("title", "׷�꽣");
	set("gender", "����");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "����Ƿ�������,����һ����֪���Ǹ�����Ȼ���ˡ�");

	set("per",random(20)+10);
	set("str", 110);
	set("int", 110);
	set("con", 110);
	set("dex", 95);
	set("level",210);
	set("repute",50000000);

	set("chat_chance_combat", 20);		//����NPCʹ�þ��еļ���
	
	set_inquiry("���ſ�ջ", "����һ��־ͬ���ϵ��ֵܽ����齨�İ��ɡ�");
	set_inquiry("��һ", "������һֻ�Ǹ���������,ͽ�����ն���");
	set_inquiry("����", "�Ǽһ��ֲ�֪��������ȥ��MM�ˡ�");

	set("hp", 132000);
	set("max_hp", 132000);
	set("mp", 72000);
	set("max_mp", 72000);
	set("mp_factor", 500);
	
	set("combat_exp", 210000000);
	set("score", 500000);
	
	set_skill("buddhism", 780);
	set_skill("literate", 780);

	set_skill("blade", 780);
	set_skill("claw", 780);
	set_skill("club", 780);
	set_skill("cuff", 780);
	set_skill("dodge", 780);
	set_skill("finger", 780);
	set_skill("force", 780);
	set_skill("hand", 780);
	set_skill("parry", 780);
	set_skill("staff", 780);
	set_skill("strike", 780);
	set_skill("sword", 780);
	set_skill("whip", 780);

	set_skill("banruo_zhang", 780);
	set_skill("cibei_dao", 780);
	set_skill("damo_jian", 780);
	set_skill("fengyun_shou", 780);
	set_skill("wuying_jian", 780);
	set_skill("hunyuan_yiqi", 780);
	set_skill("jingang_quan", 780);
	set_skill("longzhua_gong", 780);
	set_skill("luohan_quan", 780);
	set_skill("nianhua_zhi", 780);
	set_skill("pudu_zhang", 780);
	set_skill("qianye_shou", 780);
	set_skill("sanhua_zhang", 780);
	set_skill("riyue_bian", 780);
	set_skill("shaolin_shenfa", 780);
	set_skill("weituo_gun", 780);
	set_skill("wuchang_zhang", 780);
	set_skill("xiuluo_dao", 780);
	set_skill("yingzhua_gong", 780);
	set_skill("yijinjing", 780);
	set_skill("yizhi_chan", 780);
	set_skill("zui_gun", 780);

	map_skill("blade", "cibei_dao");
	map_skill("claw", "longzhua_gong");
	map_skill("club", "wuchang_zhang");
	map_skill("cuff", "luohan_quan");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("finger", "nianhua_zhi");
	map_skill("force", "yijinjing");
	map_skill("hand", "fengyun_shou");
	map_skill("parry", "yizhi_chan");
	map_skill("staff", "weituo_gun");
	map_skill("strike", "sanhua_zhang");
	map_skill("sword", "wuying_jian");
	map_skill("whip", "riyue_bian");

	prepare_skill("finger", "nianhua_zhi");
	prepare_skill("strike", "sanhua_zhang");
	
	set("no_kill",1);
	set("no_���־�",1);
	set_temp("apply/no_���־�",1);
	set_temp("apply/no_ǧ���׹�",1);
	set_temp("apply/no_��˼����",1);
	set_temp("apply/no_�ƺ�����",1);
	set_temp("apply/no_���־�",1);
	set_temp("apply/no_�������",1);
	set_temp("apply/no_ƴ��",1);
	set_temp("apply/no_��Ѫ��",1);
	set_temp("apply/no_���־�",1);
	
	set("bigboss",1);
	set_weight(50000000);

	set("apply/armor", 1050);
    set("apply/damage", 920);

	set("chat_chance", 5);

    carry_object("changjian")->wield();
	carry_object("xuan_cloth")->wear();

	set("family/family_name","������");
	
	call_out(do_full, 7200);
	
}

static void do_full(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(!me->query_temp("fight/is_fighting"))
	{
		message_vision("\n$HIR$N�������£��˹���Ϣ��", me);
		me->set("mp",me->query("max_mp"));
		me->set("hp",me->query("max_hp"));
	}
	me->call_out(do_full, 7200);
}

virtual char * chat_msg()				
{
	switch(random(4))
	{
	case 0:
		return "����˫�ֺ��𣬿��з�����𣺡�����������ħ������ȥ�Ȼ���ȥ����";
	case 1:
		return "���������ָ����ʾ�����ŷ�ħ���Ͼ���ָ����ͬʱ���������̸�У�����ͬ��һŵǧ���ء���";
	case 2:
		return "�������ε�˵������������Ȼ������,�����������������ˡ���";
	case 3:
		return "�����޿��κε�ҡ��ҡͷ������˵�����������޷�ĺ�������ô���Գɷ��أ��ѹֽ������ֲ���������ϣ����������������Ķ������԰�������ǡ���������������";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * ling = PresentName("changjian", IS_ITEM);
	if(query_weapon() == ling && ling)
	{
		switch(random(3))
		{
		case 0:
			perform_action("sword wuying", 1);
			break;
		case 1:
			perform_action("force roar", 1);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		}
	}
	else
	{
		switch(random(4))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			perform_action("finger foxue", 1);
			break;
		case 2:
			perform_action("parry dian", 1);
			break;
		case 3:
			perform_action("parry jingmo", 1);
			break;
		}
	}
	return 0;
}

void die()
{
	CContainer * obj = environment();
	DTItemList * list = obj->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	CChar * me;
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		me = (CChar *)obj;  
		if(!userp(me))	continue;
		//���һ���򵹵��˽���ý�����һ����ʸ�
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>152 )
		{
			message_vision("$HIR$N�������$n�㾹Ȼ�ܴ�����յĽ�����һ,�������ȥ��һ���ˣ���", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level11"))
				me->set("18dy/level12",1);
			me->move(load_room("�߲���ɽ����"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
