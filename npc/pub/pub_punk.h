// pub_punk.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_punk);

virtual void create()
{
	set_name("С��å", "punk" );

	set("icon", banditi);
	set("gender", "����" );
	set("age", 18);
	set("long", "����һ�����ֺ��е�С��å��");
	
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set("combat_exp", 500);
	set("shen_type", -1);
	set("str", 25);
	set("dex", 20);
	set("con", 18);
	set("int", 15);
	set("attitude","heroism");
	set("chat_chance", 2);
	carry_object("cloth")->wear();

	set_inquiry("��С��", ask_me);
	set_inquiry("�仨","�仨�Ǹ�С�Ѹ������Ҿ��ڴ�ȳ����ߡ�");
	set_inquiry("��","������С��Ū���ģ�ζ�����治��");

}

virtual char * chat_msg()
{
	switch (random(4) )
	{
	case 0:
		return  "��å�������ֵ�˵�������������а������������һ�����ƣ���С�������־�Ȼ������һ����������";
	case 1:
		return  "��å����ǽ�Ǵ����˯���ˣ�˯����Ҳ��֪�뵽��ʲ�ᣬ����ߺߵ����ҿ�������ѩ�׵Ĵ��ȣ��Ҿ����ˡ������ġ�ඡ�";
	case 2: 
		return  "��å�������Լ��Ŀڴ���̾�˿���˵��������Ǯ������С��ƭȥ�ˣ�����ȥ�Ҵ仨�ˡ�";
	case 3:
		return  "��å���¶��һ˿аЦ��˵�����仨��������湻�������������̵Ĺ���������!";
	}
	return "";
}

static char * ask_me(CNpc * who, CChar * me)
{
	if ( me->query_temp("marks/��") ) 
	{
		who->say("�㻹����û��? �ʻ���ҪǮ��?", me);
	}
	else 
	{
		who->say("��С�����������Ǳ�����ˣ�������ǰ�����������������С����Ǯ�����䣬�ҿ����е�����С��ȭ��ͦ�����ġ�",me);

		me->set_temp("marks/��", 1);
		who->say("��Ҫ����С�����鷳��? ����ס�ڲ��������棬�����Ƕ����˸�С���ӡ�", me);
	}

	who->SendMenu(me);
	return "";
}

NPC_END;