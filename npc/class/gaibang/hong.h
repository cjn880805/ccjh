//hong.h
//Lanwood 2000-01-06

ZUSHI_BEGIN(CNgaibang_hong);

virtual void create()
{
	set_name("��л�", "hong qigong");
	set("nickname", "��ָ��ؤ");
	set("gender", "����");
	set("age", 75);
	set("long", 
		"������ؤ���ʮ���ΰ������ųơ���ؤ���ĺ�л���ү�ӡ�");
	set("attitude", "peaceful");
	set("icon",begger);
	set("shen_type", 1);

	set("beggarlvl", 9);
	
	set("str", 35);
	set("int", 25);
	set("con", 33);
	set("dex", 24);

	set("chat_chance", 1);
	set("chat_chance_combat", 30);
	
	set_inquiry("������", "����������������������������ƽ����");
	set_inquiry("ؤ��", "��·��������������һ��ε����ȳ���Ѱ���������飬ͣ�������Ҽ��硣");
	set_inquiry("��ʦ", "�����ȥ���������Ұ��ܶ��³�нţ�����Ϊʦ��");

	set("hp", 24500);
	set("max_hp", 24500);
	set("mp", 14000);
	set("max_mp", 14000);
	set("mp_factor", 300);
	
	set("combat_exp", 62500000);
	set("score", 400000);
	 
	set_skill("force", 270);             // �����ڹ�
	set_skill("huntian_qigong", 270);    // ��������
	set_skill("unarmed", 400);           // ����ȭ��
	set_skill("xianglong_zhang", 300);   // ����ʮ����
	set_skill("dodge", 220);      	     // ��������
	set_skill("xiaoyaoyou", 220);        // ��ң��
	set_skill("parry", 230);             // �����м�
	set_skill("staff", 300);             // ��������
	set_skill("dagou_bang", 250);        // �򹷰���
	set_skill("begging", 250);           // �л�����
	//set_skill("checking", 250);          // ����;˵
	set_skill("xunshou_shu", 180);
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong_zhang");
	map_skill("staff", "dagou_bang");
	
	create_family("ؤ��", 17, "����");

	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);

	carry_object("yuzhu_zhang");
	set("no_huan",1);
	
//	carry_object("jiaohuaji");		�л���
}

virtual char * chat_msg()
{
	switch(random(3))
	{
	case 0:
		return 	"��л�̾�˿�����������������ʱ���ٳԵ��ض����ġ��л�������������";
	case 1:
		return 	"��л�˵�������׻�˵�����ڽ��ϡ��������Ͻл��ص��������ݿ�������";
	case 2:
		return "��л��૵���������ؤ��ġ�����ʮ���ơ���������Ե����Ʒ�����";
	}

	return 0;
}

virtual char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("staff zhuang", 1);
		break;
	case 1:
		perform_action("unarmed xianglong", 1);
		break;
	case 2:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];

	if (me->query_str() < 20 || me->query_con() < 20) 
	{
		say(snprintf(msg, 255, "���л�����Ҫ�ܳԿ����ͣ����ҿ�%s�������ƺ����ʺϵ��л��ӣ�", query_respect(me)), me);
		SendMenu(me);
		return;
	}

	if (me->querymap("family/family_name") &&
	    DIFFERSTR(me->querystr("family/family_name"), "ؤ��") && me->query("beggarlvl") > 8) 
	{
		say(snprintf(msg, 255, "%s��Ȼ������ʦָ�㣬�α��������Ͻл��أ�", query_respect(me)), me);
		SendMenu(me);
		return;
	}

	command(snprintf(msg, 255, "recruit %ld", me->object_id()));
	me->set("class", "beggar");
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	if (DIFFERSTR((who->environment())->querystr("base_name"), "��������10" ))
		return notify_fail("�����������");
	if(EQUALSTR(ob->querystr("id"),"bao guo") && EQUALSTR(ob->querystr("obj"),id(1)) &&
		EQUALSTR(ob->querystr("owner1"),who->id(1)))
	{
		who->add_temp("lin/baoguo/count",1);
		int exp=ob->query("exp");
		int repute=ob->query("repute");
		
		tell_object(who, snprintf(msg, 255, "\n$YEL%s���˵�ͷ�����������͹����İ�����",name(1)));
		tell_object(who, "\n$YEL��������渣���ھ�Ѻ�˰��ڵ�����");
		tell_object(who, snprintf(msg, 255, "$YEL�����%d�ľ��齱������������������%d��",exp,repute));
		g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s(%s)ѹ�˰��ڳɹ��������%d�ľ��齱������������������%d�㣡", who->name(1), who->id(1),exp,repute));
		who->delete_temp("lin/baoguo/start");
		if(who->query_temp("no_fei"))who->delete_temp("no_fei");
		who->add("combat_exp",exp);
		who->add("repute",repute);
		who->UpdateMe();
		destruct(ob);
		return 1;
	}

	if (ob->query("food_supply") <= 0)
		return 0;
	
	if (DIFFERSTR(ob->querystr("name"), "�л���")) 
	{
		say(snprintf(msg, 255, "�Ͻл���%sûʲô��Ȥ����", ob->name()), who);
		SendMenu(who);
		return 0;
	}

	say("����������������ԵĽл���ѽ��", who);
	command(snprintf(msg, 255, "use %ld", ob->object_id()));
	say("�벻����СС��ͣ���˼ȴ��ϸ���͸�������ض�һ����", who);

	if (who->querymap("family/family_name") &&
	    DIFFERSTR(who->querystr("family/family_name"), "ؤ��")) 
	{
		say("�㻹���������ʲô��", who);
		SendMenu(who);
		return 1;
	}

	CContainer * ob_yzz;

	if( (ob_yzz = PresentName("yuzhu_zhang", IS_ITEM)) )
    {
		ob_yzz->move(who);
		say("������ȸ����Ҷ����ˣ����͸�����������ɡ�", who);
	}
	else
	{
		say("���������ò���ʱ���������Ѿ��������ˡ�", who);
    }

	SendMenu(who);
	return 1;
}


ZUSHI_END;
