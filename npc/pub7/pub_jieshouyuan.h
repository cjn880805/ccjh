//pub_jieshouyuan.h������Ա
// dieer 2002 9.9

NPC_BEGIN(CNpub_jieshouyuan);

virtual void create()
{
	set_name("����Ա","jieshouyuan");
	
	set("gender", "����");
	set("age", 26);
	set("long","����һ����׳��ʵ��С���ӣ���Ϊ������������첲��¡��������������һ��ļ��⡣��ר�Ÿ������ת�Ʒ���������Ʒ��");
	set("attitude", "friendly");
	set("icon", 40);
	
	set("per", 15);
	set("str", 30);
	set("int", 20);
	set("con", 30);
	set("dex", 10);
	
	set("max_hp", 1000000);
	set("hp", 900000);
	set("max_mp", 1000);
	
	set_skill("force", 50);
	set_skill("unarmed",50);

	set("coin",50000);
	
	set_inquiry("ת�ƶ���", "Ҫת��ʲô��Ʒ����ֱ�Ӹ��Ұɣ���������������ô��һ�ζ�������20��������");
	set_inquiry("�۸�", ask_jiage);
	set("no_huan",1);
}

virtual void init(CChar * me)
{
	CNpc::init(me);
	
	char msg[255];
	switch(random(2))
	{
	case 0 :
		say(snprintf(msg,255,"��λ%s�����Ƿ�Ҫ���˷���������Ʒת�Ƶ���ķ�����ȥ��",query_respect(me)),me);
	case 1:
		say("������Ϊ��ת����Ʒ���շѷǳ����ˣ������ְ�ȫ�������Ծ��ܷ��ģ�",me);		
	}
	SendMenu(me);
}

static char * ask_jiage(CNpc * me, CChar * who)
{
	char msg[255];
	if(me->query("coin"))
		snprintf(msg,255,"��Ϊ��ת����Ʒ���շѷǳ�����,ÿ��������%d�ɣ�",me->query("coin"));
	else
		snprintf(msg,255,"��ξͲ������Ǯ�˰ɣ�");
	me->say(msg,who);
	me->SendMenu(who);
	return 0;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	
	//�շѰ���
	if (EQUALSTR(ob->querystr("id"), "coin") && !query("coin") )
	{
		say("Ǯ�����Լ����Űɣ�", who);
		SendMenu(who);
		return 0;
	}
	else if (EQUALSTR(ob->querystr("id"), "coin") )
	{
		if(ob->query("value") >= query("coin"))
		{
			destruct(ob);
			say("�ã�Ǯ�Ѿ��յ��ˣ��ҾͰ����һ����Ʒ�ɡ�", who);
			who->add("item/coin",1);
			SendMenu(who);
			return 1;
		}
		else
		{
			say("��ô��Ǯ�������Ҹ���ᶫ����", who);
			SendMenu(who);
			return 0;
		}
	}
	//����������Ʒ��Ҫ
	if(ob->is_character())
	{
		say("��Ķ����ҿɲ�Ҫ��", who);
		SendMenu(who);
		return 0;
	}

	//����
	if(who->query("item/count") < 20)
	{
		if((who->query("item/coin") && query("coin")) || !query("coin"))
		{
			who->add("item/coin",-1);
			if(who->query("item/coin")<=0)
				who->del("item/coin");
			who->add("item/count",1);
			snprintf(msg,255,"item/item%d",who->query("item/count"));
			who->set(msg,ob->querystr("base_name"));
			snprintf(msg,255, "�ã��Ѿ��յ����%s�ˣ��ܹ��Ѿ�����%d����Ʒ,������Ҫת��ʲô��",ob->querystr("name"),who->query("item/count"));
			say(msg, who);
			SendMenu(who);
			destruct(ob);
			return 1;
		}
	}
	else
	{
		say("���Ѿ���������20���������ٶ��ҿɰ᲻���ˣ�", who);
		SendMenu(who);
	}
	return 0;
}


NPC_END;