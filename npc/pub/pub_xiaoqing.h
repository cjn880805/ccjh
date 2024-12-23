//pub_xiaoqing.c
// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_xiaoqing);

virtual void create()
{
	set_name("С��", "xiao qing");

	set("icon", young_woman2);
	set("title", "ҩ��ʦ");
	set("gender", "Ů��" );
	set("age", 16);
	set("long","���Ǹ��������ɵ�С������ĺ����أ�һϮ���£�ȴҲ�Ե��������¡�С����˷ǳ����顣��Ҫ�Ǹ�����������ͻ������һ�㣡");
	set("attitude", "friendly");
	set("shen_type", -1);
	
	set("str", 20);
	set("int", 29);
	set("con", 23);
	set("dex", 22);
	
	set("max_hp", 420);
	set("mp", 120);
	set("max_mp", 120);
	
	set("combat_exp", 60000);
	set("score", 1000);
	
	set_skill("force", 26);
	set_skill("dodge", 23);
	set_skill("unarmed", 24);
	set_skill("parry", 22);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 17);
	set_temp("apply/armor", 10);
	
	set_temp("dan",0l);
	set_temp("times",5);
	create_family("����ɽ��", 5, "����");
	
	set_inquiry("���ڴ���","�Ѿ�ˤ���ˡ�");
	set_inquiry("����" ,"������Сʱ������ѣ�");
	set_inquiry("�ߵ���",inquiry_gao);
	
	carry_object("qingpao")->wear();
	set("no_huan",1);
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];

	if(random(2)==1)
		return snprintf(msg,255,"��λ%s���������������ˡ�",query_respect(ob) );
	
	
	return snprintf(msg,255,"��λ%s������ɡ� ",query_respect(ob) );	
}

static char * inquiry_gao(CNpc *me,CChar *who)
{
	char msg[255];

	if(me->query_temp("dan")==3) 
		return "��û�����Ѿ��������";

	if(me->query_temp("times")==0) 
		return "ʦ�������Ѿ������������ߵ��ࡻ�ˣ�";

	snprintf(msg,255,"��λ%s������˵��ʦ�����������ߵ��ࡻ������", query_respect(who));

	switch (me->query_temp("dan"))
	{
	case 0:
		strcat(msg, "��һֻ���ߵ���һֻ���ߵ���"  );
		break;
	case 1: 
		strcat(msg, "����һֻ���ߵ���");
		break;
	case 2: 
		strcat(msg,  "����һֻ���ߵ���");
		break;
	}
	me->say(msg, who);
	me->say("��֪��λ�������ܰ�����أ�", who);
	me->SendMenu(who);
	return "";
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("base_name"), "qingdan")
		&&  DIFFERSTR(ob->querystr("base_name"), "jindan" ))
		return notify_fail("С�಻��Ҫ���������");

	if ( query_temp("times")==0 )
		return notify_fail("С�������Ѿ��������ߵ��ࡻ�ˡ�");

	if ( EQUALSTR(ob->querystr("base_name"), "jindan" ))
	{
		if (query_temp("dan")==2)
		{
			say("�һ������ߵ�����ȱ���ߵ���", who);
			SendMenu(who);
			return 0;
		}

		add_temp("dan", 2);

		if (query_temp("dan")==2)
		{ 
			say("С�࿴�����ߵ������˵���������§����Ĳ���˵���������ߵ��ʹ󹦸���ˣ�", who);
			SendMenu(who);
			return 1;
		}
	}

	if (  EQUALSTR(ob->querystr("base_name"), "qingdan" ))
	{
		if (query_temp("dan")==1)
		{
			say("С��һ���ǣ������ź��ض���˵���һ�����ߵ�����ȱ���ߵ���",who);
			SendMenu(who);
			return 0;
		}

		add_temp("dan",1);
		if (query_temp("dan")==1)
		{ 
			say("С�࿴�����ߵ������˵�����������§����Ĳ���˵������ͽ��ߵ��󹦸���ˣ�",who);
			SendMenu(who);
			return 1;
		}
	}

	message_vision("С�����������$Nһ�¡�\nС���ֽ������ذ���ֻ�ߵ�Ͷ��ҩ���У��ּ���һЩ��֪��ʲô��ҩ�ۣ�Ȼ���ϡ�ﻩ��һҡ���٣����ߵ��ࡻ�����ˡ�\nС������صشս�$N����˵��Щʲô��\nС�����������$Nһ�ۣ������ˡ�", who);
	say("��͵͵����һ�㡺�ߵ��ࡻ�͸��㣬ʦ�����ᷢ�ֵġ�", who);
	SendMenu(who);

	//�ߵ���
	load_item("shedangao")->move(who);
	set_temp("dan",0l);
	add_temp("times",-1);
	return 1;
}

NPC_END;