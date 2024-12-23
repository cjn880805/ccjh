// wudang_dingdang.c ����

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwudang_dingdang);

virtual void create()
{
	set_name("����", "ding dang");
	set("gender", "Ů��" );
	set("age", 18);
        set("icon",girl1);

	set("long", "һ��ʮ�߰������Ů�����������ӣ�һ�Ź��������������ޡ� ");
	set("shen_type", 1);
	set("combat_exp", 100000);
	set("str", 18);
	set("dex", 22);
	set("con", 25);
	set("int", 35);
	set("per",30);
	set("attitude", "friendly");
	
	set("hp", 2000);
	set("max_hp", 6000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 50);
	
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 200);
	set_skill("taiji_shengong", 200);
	set_skill("taiji_quan", 200);
	set_skill("tiyunzong", 500);
	
	map_skill("force","taiji_shenfong");
	map_skill("unarmed","taiji_quan");
	map_skill("parry","taiji_quan");
	map_skill("dodge","tiyunzong");
	set("chat_change",15);
	
	set_inquiry("ʯ����",inquiry_yu);
	set_inquiry("Ħ����","  ǰ������ɽ�����ˣ���ҪС��ѽ���Ǹ���ͷ���书��ǿѽ�� ");
	set_inquiry("������","  ��˵����ʯ�����������ҾͲ�֪���ˡ� ");

	set_temp("shoupa",1);
	
	carry_object("shouzhuo")->wear();
	carry_object("yupei")->wear();
	add_money( 1000);
}

virtual char * chat_msg()
{
	switch (random(4))
	{
	case 0:
		return "������߶��: Ҳ��֪���ҵ�����������ô���ˡ� ";
	case 1:
		return "��������Ĩ�˰����ᡣ ";
	case 2:
		return "����һ��ţ�˵��: ���У���Ҫ��Ħ���°��ҵ�����Ȼ����� ";
	case 3:
		return "����̾�˿�����˵��: Ҫ����������ͺ��ˡ� ";
	}
	return "";
}

static char * inquiry_yu(CNpc *who,CChar *me)
{
	CContainer * obn;
	char msg[255];
	
	who->say(snprintf(msg,255,"��λ%s���������ҵķ���� ����ȥ����ѩɽ�ɱ�л�̿�ץȥ����������������Ҳ��֪�����ǻ���� ", query_respect(me) ), me );

	if(who->query_temp("shoupa")==0)
	{  
		who->say("���Ѿ�����ȥĦ���¿����ˣ�Ҳ��֪����ô���ˡ� ", me);
		who->say("�漱�ˣ�", me);
		who->SendMenu(me);
		return 0;
	}

	who->say("��������һ����������������֮��㿴���ҵ����� ��Ͱ��������������������׵ġ������ˡ� ",me);
	who->SendMenu(me);
	obn=load_item("shoupa");//����
	obn->move(me);
	who->set_temp("shoupa",0l);
	message_vision("$N�ӻ����ó�һ��Ư��������������$n��", who, me);
	return 0;
}

NPC_END;