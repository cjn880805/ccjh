//taohuadao_yan.c
//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNtaohuadao_yan);

virtual void create()
{
	set_name("��ӢӢ", "cheng ying");
	set("gender", "Ů��" );
	set("age",18);
        set("icon",girl2);

	set("long","��ӢӢ�ǻ��Ϲִ�С�����Ĺ�Ů���ɻ��Ϲ����̵ֽ���һ�����˳ƾ�������ַ�������һ�������ʳ����������");
	set("per", 30);
	set("class", "scholar");
	set("combat_exp", 10000);
	
	set_skill("unarmed",30);
	set_skill("luoying_shenzhang",30);
	set_skill("dodge", 30);
	set_skill("anying_fuxiang" , 30);
	set_skill("force",30);
	map_skill("dodge", "anying_fuxiang");
	map_skill("unarmed","luoying_shenzhang");
	
	set("force", 500);
	set("max_force", 500);
	set("force_factor",0l);
	
	set("chat_chance", 7);
	create_family("�һ���", 3, "����");
	
	carry_object("cloth")->wear();
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "�����һ�����ɫ��������ӭ�����ͣ� ";
	case 1:
		return "���Ҽ���������ˣ� ";
	case 2:
		return "�������������һ������������������µ�һѽ�� ";
	}
	return "";
}

virtual void init(CChar * me)
{
	if(userp(me))
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 2, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	CContainer * teatp;
	char msg[255];

	if(! who) return;

	if ( who->query_temp("taohua/�跹") )
		me->say(snprintf(msg,255,"��λ%s����ã���ӭ�����һ����� ", query_respect(who) ));
	else
	{
		tell_room(me->environment(),snprintf(msg,255,"��ӢӢ���ϲ跹��΢Ц��˵������λ %s����ã���ӭ�����һ��������÷��� ",query_respect(who) ));
		teatp= load_item("cha");//���ɲ�
		teatp->move(who);
		teatp= load_item("gao");//��ѩ����
		teatp->move(who);
		
		me->say("�������������ģ�����Ʒ���� ");
		who->set_temp("taohua/�跹", 1);
	}
}

NPC_END;