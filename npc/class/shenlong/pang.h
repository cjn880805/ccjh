//pang.h
//Lanwood
//2001-03-11

NPC_BEGIN(CNshenlong_pang);

virtual void create()
{
	set_name("��ͷ��", "pang toutuo");

	set("icon",young_man2);	
	set("title", "�������󻤷�");
	set("nickname", "�ɶ�������");
	set("long", "��ͷ��������,�����ݵó���;����Ƥ����ͷ,˫Ŀ����,������罩ʬһ��." );
	set("gender", "����");

	set("age", 44);
	set("str", 35);
	set("dex", 20);
	set("con", 30);

	set("max_hp", 12500);
    set("hp",6000);
	set("max_mp",1500);
    set("mp",1500);
	set("mp_factor", 80);
	set("combat_exp", 900000);
	set("score", 40000);
	set("shen_type", -1);

	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 40);

    set_skill("force", 150);
    set_skill("dodge", 150);
    set_skill("unarmed", 150);
    set_skill("strike", 130);
    set_skill("parry", 150);
    set_skill("staff", 130);
    set_skill("sword", 130);
	set_skill("literate", 120);
	
	set_skill("shenlong_xinfa", 130);
	set_skill("yixingbu", 130);
	set_skill("shenlong_bashi", 130);
	set_skill("huagu_mianzhang", 130);
	set_skill("shedao_qigong", 130);
	
	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong_bashi");
	map_skill("strike", "huagu_mianzhang");
	map_skill("parry", "shedao_qigong");
    map_skill("sword", "shedao_qigong");
	prepare_skill("strike", "huagu_mianzhang");
	prepare_skill("unarmed", "shenlong_bashi");

	create_family("������",2,"����");

	set_inquiry("����",  "����Ƣ������,Ҫ�������Ĳźá�");
	set_inquiry("�ں�", "���겻��!�����ɸ�!��������!������ʥ!");       
	
	carry_object("cloth")->wear();
	add_money(1000);
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if (DIFFERSTR(me->querystr("party/party_name"), "������")) 
	{
		say("�㲻�Ǳ��̽���, ����������!", me);
		SendMenu(me);
		return;
	}

	if (me->query_skill("shenlong_xinfa",1) < 50 ) 
	{
		say ("��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°�!",me);
		SendMenu(me);
		return;
	}

	if(me->query_skill("shedao_qigong",1) < 50 ) 
	{
		say(" ��ı����湦̫���ˣ�����ŬŬ�������һ�°�!",me);
		SendMenu(me);
		return;
	}

	if (me->query("repute") > -10000  ) 
	{
		say("�������������������������������ְ׵�����򽻵�������ذɣ�", me);
		SendMenu(me);
		return;
	}

	say("�ܺã��ܺá�");
	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
}

SHENLONG_END;