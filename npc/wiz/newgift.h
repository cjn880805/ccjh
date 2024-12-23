//newgift.h
//code by zwb
//12-25

NPC_BEGIN(CNnewgift);


virtual void create()
{
	
	set_name("����ʹ��","liwu shizhe");

	set("icon", young_woman1);
	set("title", "����ʹ��");
	set("gender", "����" );
	set("age", 43);
	set("per", 3);
	set("long","���������û������ʹ��");
	
	set("max_hp", 2400);
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("grant", 99);
	set_inquiry("������������","����һ�����,�ҾͰ�������е������û��ͳ����");
	set_skill("literate", 70);
	set_skill("dodge", 200);
	set_skill("unarmed", 100);
	set("wait_time", 60);
	set("no_huan",1);
//	carry_object("cloth")->wear();
}

virtual int accept_object(CChar * who, CContainer * ob)
{

	if (EQUALSTR(ob->querystr("id"), "coin") )
	{
		destruct(ob);
		g_Channel.do_channel(&g_Channel, 0, "wiz", "$HIR����������������죡�������µ�һ�꼴������֮�ʣ����ǽ������е�������������һ�����ص���Ʒ��");
		g_player();
		g_lost();

		return 1;
	}

/*static char * do_doom(CNpc * me, CChar * who)
{
	if(! wizardp(who)) return "ֻ����ʦ����Ȩ�޷�������";

	if(me->query("newyear")) return "�ҵļ���û��ô��ģ�˵һ�ξ͹��˰ɣ�";
	me->set("newyear", 1);
	g_Channel.do_channel(me, NULL, "wiz", "$HIR\n\n\n              ����������������죡��\n\n\n              �����µ�һ�꼴������֮�ʣ����ǽ������е���������\n\n\n              ����һ�����ص���Ʒ��\n\n\n\n");
	me->call_out(do_liwu, 6);

	me->command("force_save 0 all");
	return 0;
}

static void do_liwu(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
		
	if(me->query("wait_time") <= 0)
	{
		g_Channel.do_channel(me, NULL, "wiz", "$HIR\n\n\n              ��������˾ȫ��Ա��\n\n\n              ��ף��������������֣�\n\n\n");
		g_player();
		g_lost();
		return;
	}

//	char msg[255], tmp[40];

//	g_Channel.do_channel(me, NULL, "wiz", snprintf(msg, 255, "$HIR\n\n\n            ����Ļ���%s���ӣ����ǽ��ǲ���������\n\n\n", chinese_number(me->query("wait_time"), tmp)));
	me->add("wait_time", -1);

	me->call_out(do_liwu, 600);
}*/

int g_player()
{
	MAP2USER * user;
	iterator_user p;
	CUser * obj;

	user = users();
    for ( p=user->begin(); p!=user->end(); p++)
    {
		obj = p->second;
	
		char msg[255];
		
		CContainer * gift;

		snprintf(msg, 255, "����Ʈ��������һ�����ӣ���ƫ����������Ļ��С���\n���һ����������һ�����������������");
		
        tell_object(obj,msg);

		if (EQUALSTR(obj->querystr("gender"), "����"))	//��Ҷ��
		{
			gift=load_item("newyear");
			gift->move(obj);
		}
		
		if (EQUALSTR(obj->querystr("gender"), "Ů��"))	//Ů����
		{
			gift=load_item("newyear");
			gift->move(obj);
		}
		
		if (EQUALSTR(obj->querystr("gender"), "����"))	//׳����
		{
			gift=load_item("newyear");
			gift->move(obj);
		}
    }
    
	return 1;
}

int g_lost()
{
	return 1;
}

NPC_END;