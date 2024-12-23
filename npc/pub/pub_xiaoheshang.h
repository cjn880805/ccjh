// pub_xiaoheshang.c

// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_xiaoheshang);

virtual void create()
{
	set_name("С����", "xiao heshang" );

	set("icon", young_monk);
	set("gender", "����" );
	set("age", 14);
	set("long", "���Ǹ�������ɵ�С����");
	set("str", 15);
	set("dex", 20);
	set("con", 17);
	set("int", 15);
	set("shen_type", 1);
	
	set_skill("unarmed", 50);
	set_skill("dodge", 35);
	set_temp("apply/attack", 5);
	set_temp("apply/defense", 5);
	set("combat_exp", 7500);
	
	set("chat_chance", 20);
	set("attitude", "peaceful");
	set_inquiry("����" ,ask_dingli);
	set_inquiry("����",ask_changli);
	set_inquiry("����","������������Ȼ���ҵ����˶�����ʶ��");
	
}

virtual char *chat_msg()
{
	switch (random(4))
	{
	case 0:
		return "С���е������ް����ӷ�";
	case 1:
		return "С���е����������շ�������";
	case 2:
		return "С���е������޴�����������";
	case 3:
		return "С���е������޴�ȴ󱯹�����������";
	}
	return "";
}


static char * ask_dingli(CNpc *ob,CChar *me)
{
	if ( me->query("chanxin/save")>=2 )
	{
		me->set("chanxin/save",3);
		return "������㻹����һ��ģ�";		
	}
	else
	{
		return "����Ҵ��������������ԣ�";
	}

	return "";
}

static char * ask_changli(CNpc *ob,CChar *me)
{
	if ( me->query("chanxin/save")>=3 )
	{
		me->set("chanxin/save",4);
		return "����ỹ����Ҫ��¥�����ȵ��ô��";
	}
	else
	{
		return "����Ҵ��������������ԣ�";
	}

	return "";
}

/*
void serve_tea(CChar * who)
{
	CContainer * obn;
	
	if( !who->query_temp("marks/sit") )
		return;
	
	obn = load_item("xiangcha");//���
	obn->move(environment());
	message_vision("С�����ó���ɳС��������˱���裬�������ϣ�", who);
	
	obn = load_item("jiuping");//��ƿ
	obn->move(environment());
	obn = load_item("pork");//������
	obn->move(environment());
	obn = load_item("geng");//��������
	obn->move(environment());
	obn = load_item("shrimp");//����Ϻ��
	obn->move(environment());
	obn = load_item("chicken");//�л�ͯ��
	obn->move(environment());
	obn = load_item("fish");//��������
	obn->move(environment());
	message_vision("Ȼ���ó�һƿ�ƺ�һ���̺óԵķ������ϣ�", who);
	
	return;
}
*/

NPC_END;