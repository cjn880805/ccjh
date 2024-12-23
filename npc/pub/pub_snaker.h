// pub_snaker.c
// code by Fisho
// date:2000-12-17
//inherit F_DEALER;

VENDOR_BEGIN(CNpub_snaker);

virtual void create()
{
	set_name("������",  "snaker" );

	set("icon", young_man6);
	set("long", "����һ���������������ˡ�");
	set("title", "��������");
	set("nickname",  "�߼���"  );
	set("gender", "����");
	set("age", 33);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);
	
	set_skill("unarmed", 75);
	set_skill("dodge", 65);
	set_skill("parry", 65);
	set_skill("force", 60);
	
	set("mp", 400);
	set("max_mp", 400);
	set("mp_factor", 20);
	set("combat_exp", 30000);
	set("snake_mount" ,3);
	set("score", 10000);
	
	set("chat_chance",5);
	
	set_inquiry("����ɽ","��������ߵ��۾����ð���ɽ���߾��������ġ�");
	set_inquiry("�ߵ���","�ҵ��ߵ������θ������ˣ���Ч������");
	
	carry_good("fen",500);
	
	carry_object("baipao")->wear();
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "������ߺ�ȵ�:ͣһͣ����һ�������Ϻõ��ߵ��۳����ˣ�";
	case 1:
		return "�����˰����󻮳�һ�����ӣ��ַ����ߵ��ۣ��ף���Ѫ����ֹͣ�ˡ�";
	case 2:
		return "�����˰��������������ȥ���������ʵ�����������û����";
	}
	return "";
}

/*
virtual char * greeting(CChar * ob)
{     
	CContainer * obn;
	char msg[255];
	if ( EQUALSTR(ob->querystr("family/family_name"), "����ɽ��"))
	{
		if(!(ob->present("shenshe") )&&random(2)==1)
		{
			tell_object(ob,snprintf(msg,255,"��λ%s���������С���·���ߡ���������ȥ�ã����õ��ģ��������İ�������",query_respect(ob) ));
			obn=load_item("shenshe");//û�и���Ʒ
			obn->move(ob);
			return "";
		}
	}
	say(snprintf(msg,255,"���������ڵ�˵����λ%s�����ҵ��ߵ��۰ɣ��������⡣",query_respect(ob) ));
	return "";
}

virtual int accept_fight(CChar * ob)
{
	CContainer * obn;
	if(!( (ob->environment() )->present("mang she") ) )
	{
		add("snake_mount", -1);
		if(!query("snake_mount")) 
		{
			message_vision("������ŭ�� �㻹��ƭ���ӵ������ޣ��� ",ob);  
			return 1; 
		}
		message_vision("�����˴��һ����С�Ӿ��Ҹ����ӹ���ȥ�������ߵ�������", ob);
		obn=load_item("mangshe");//û�и���Ʒ
		obn->move(ob->environment());
		kill_ob(ob);
		return 0;
	}
	message_vision("�����˴�ŭ��������С�ӳ������ӵ�������", ob);
	return 1;
}
*/

VENDOR_END;