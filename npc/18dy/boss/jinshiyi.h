//jinshiyi ������ 

//�����ڶ���BOSS


BOSS_BEGIN(CNjinshiyi);

virtual void create()
{
	set_name("������", "jinshiyi");
	set("title", "���ַ�ؤ");
	set("gender", "����");
	set("icon", young_man3);
	set("age", 88);
	set("long",  "������������̣��,�����ƾɵ������ڲ�ס��ɢ�������İ���֮����");

	set("str", 80);

	set("int", 80);

	set("con", 80);

	set("dex", 80);

	set("per",15);

	set("level",170);



	set("chat_chance_combat", 20);		//����NPCʹ�þ��еļ���

	

	set_inquiry("����ս��", "���Ǳ�����Ľ�Ʒ,����Ҫ����ϧ�㲻�ܴ���");

	set_inquiry("ؤ��", "ؤ����书���ڰԵ�,��û���������޷�����������");

	set_inquiry("��ɱ", "����Ͳ���Ц������һս,˼˼����û����,Ҫ��˭֪����Ӯ����");



	set("hp", 72000);
	set("max_hp", 72000);
	set("mp", 47000);
	set("max_mp", 47000);
	set("mp_factor", 500);

	

	set("combat_exp", 120000000);

	set("score", 500000);

	

	set_skill("force", 620);             // �����ڹ�

	set_skill("huntian_qigong", 620);    // ��������

	set_skill("unarmed", 620);           // ����ȭ��

	set_skill("xianglong_zhang", 620);   // ����ʮ����

	set_skill("dodge", 620);      	     // ��������

	set_skill("xiaoyaoyou", 620);        // ��ң��

	set_skill("parry", 620);             // �����м�

	set_skill("staff", 620);             // ��������

	set_skill("dagou_bang", 620);        // �򹷰���

	set_skill("begging", 620);           // �л�����

	set_skill("xunshou_shu", 620);

	

	map_skill("force", "huntian_qigong");

	map_skill("unarmed", "xianglong_zhang");

	map_skill("dodge", "xiaoyaoyou");

	map_skill("parry", "xianglong_zhang");

	map_skill("staff", "dagou_bang");

	

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

	

	set("bigboss",1);

	set_weight(50000000);



	set("apply/armor", 750);
    set("apply/damage", 620);

	set("chat_chance", 5);
	set("����/gaibang/wuhui",1);
    carry_object("yuzhu_zhang")->wield();
	set("family/family_name","ؤ��");
	set("file_name", querystr("base_name"));
	Load();
	call_out(do_full, 7200);
}



int Save()
{
	char msg[255];
	return SaveToLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);
}


int Load()
{
	char msg[255];
	return LoadFromLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);	
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

		return "�����Ű���̾��������������������,��������ô�û�û��ͷ������";

	case 1:

		return "������̾���������µ�һֻ�Ǹ�����,��ϧ�м����ܿ�͸����";

	case 2:

		if(!random(30))

			return "����������ʧ���̾�������벻��������Ҳ�����������������ܣ���ϧ�Ѿ�û����̸��ҵĹ�ͽ���ˡ���";

		else

			return "������̾���������µ�һֻ�Ǹ�����,��ϧ�м����ܿ�͸����";

	case 3:

		if(!random(30))

			return "������ҡ��ҡͷ��̾��������֪��Ҫ�����ſ�����������Ӧ���ҵ�ȥ����ȥ�ˡ���";

		else

			return "������̾���������µ�һֻ�Ǹ�����,��ϧ�м����ܿ�͸����";

	}

	return 0;

}



virtual char * chat_msg_combat()

{

	CContainer * ling = PresentName("yuzhu_zhang", IS_ITEM);

	if(query_weapon() == ling && ling)

	{

		switch(random(3))

		{

		case 0:

			perform_action("staff zhuang", 1);

			break;

		case 1:

			perform_action("staff linglong", 1);

			break;

		case 2:

			perform_action("force recover", 0);

			break;

		}

	}

	else

	{

		switch(random(3))

		{

		case 0:

			perform_action("force recover", 0);

			break;

		case 1:

			perform_action("unarmed xianglong", 1);	//�����Ƶľ���

			break;

		case 2:

			perform_action("unarmed wuhuei", 1);	//�����Ƶľ���

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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>125 )
		{
			message_vision("$HIR$N�þ�ȫ�����������������...��...���ҵ�ǧ���׹�....���л�δʹ��,����ίȻ���ء�", this);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level5"))
				me->set("18dy/level6",1);
			me->move(load_room("�߲���ɳ����"));
			break;
		}
	}
	add("death_times",1);
	set("hp", 72000);
	set("max_hp", 72000);
	set("mp", 47000);
	set("max_mp", 47000);
	Save();
	CNbossnpc::die();
}



BOSS_END;

