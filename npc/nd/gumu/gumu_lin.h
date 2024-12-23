// lin.c �ֳ�Ӣ
//code by sound
//2001-07-19

NPC_BEGIN(CNgumu_lin);

virtual void create()
{
	set("icon",young_woman3);
	set_name("��ĺ��", "lin chaoying");
	set("gender", "Ů��");
	set("age", 42);
	set("long",	"�����ǹ�Ĺ�ɵĿ�ɽ��ʦ��ĺ������Ȼ�Ѿ�����ʮ���ˣ���֮ȴ����ͬ��ʮ��ͷ����������ȫ���������������һ�Գ��İ��£�ֻ��ϧ��Ե�޷ݣ�ֻ�ö��������Ĺ���ľӡ�");
	set("attitude", "friendly");
	
	set("per", 30);
	set("str", 37);
	set("int", 42);
	set("con", 45);
	set("dex", 42);
	
	set("chat_chance_combat", 6);
	set("chat_chance", 1);
	set("no_kill",1);

	set("hp", 8000);
	set("max_hp", 8000);
	set("mp", 9000);
	set("max_mp", 9000);
	set("mp_factor", 100);
	
	set("combat_exp", 3000000);
	set("shen_type", 1);
	
	set_skill("force", 300);
	set_skill("yunv_xinfa", 280);    //��Ů�ķ�
	set_skill("yunv_xinjing", 300);	 //��Ů�ľ�
	set_skill("sword", 300);
	set_skill("yunv_jian", 300);     //��Ů��
	set_skill("quanzhen_jian",300);  //ȫ�潣
	set_skill("dodge", 280);
	set_skill("yunv_shenfa", 280);   //��Ů��
	set_skill("parry", 280);
	set_skill("unarmed",280);
	set_skill("meinv_quan", 280);    //��Ůȭ��
	set_skill("literate",180);
	set_skill("taoism",220);
	set_skill("music",400);
	
	map_skill("force", "yunv_xinjing");
	map_skill("sword", "yunv_jian");
	map_skill("dodge", "yunv_shenfa");
	map_skill("parry", "meinv_quan");
	map_skill("unarmed", "meinv_quan");
	
	create_family("��Ĺ��", 1, "��ɽ��ʦ");
	set("chat_chance",  80);
	
	set_inquiry("������","�󵨺�С�ӣ�Ҳ��ֱ��������ʦ֮����");
	set_inquiry("������ʦ","������ȫ��̵��ƽ̣��Ժš������ˡ���");
	set_inquiry("��Ĺ��","�ǰ������������һ�ִ��µĹ�Ĺ��");
	set_inquiry("������",do_jian);

	carry_object("changjian")->wield();
	carry_object("qingyi")->wear();

}

virtual char * chat_msg()				
{
	if (DIFFERSTR(environment()->querystr("base_name"), "����ɽ�����ȵ�" ))
		destruct(this);
	return 0;
}

static char * do_jian(CNpc * who , CChar * me)
{	
	CContainer  * obj;

    if(!me->query_temp("gumu/ask"))
		return "������������ʲô��";
	if(me->query_temp("gumu/cyjian"))
		return "��û�аѽ��͸�����";
	if (DIFFERSTR((who->environment())->querystr("base_name"), "����ɽ�����ȵ�" ))
		return"����Ұ������ָ���һ���㶫����";
	me->set_temp("gumu/cyjian", 1);
    obj=load_item("cyjian");
    obj->move(me);
	me->delete_temp("gumu/ask");
	return "������������������������������ģ����������ȥ�������ɣ�";
}

virtual char * chat_msg_combat()
{
	switch(random(4))
	{
	case 0:
		perform_action("force recover", 0);
		break;
	case 1:
		perform_action("sword he", 1);
		break;
	case 2:
		perform_action("unarmed you", 1);
		break;
	case 3:
		perform_action("force roar", 1);
		break;
	}
	return "";
}

void init(CChar * me)
{
	CNpc::init(me);
	char msg[255];
	if(! is_fighting() && userp(me))
	{
		DTItemList * list = me->Get_ItemList();
		POSITION p = list->GetHeadPosition();
		CContainer * obj;
		while(p)
		{
			obj = list->GetNext(p);
			if(userp(obj))
			{
				message_vision(snprintf(msg, 255, "$HIR��ĺ������һ��%s,�ߵ��������ϲ��������������С�ˣ����%s���ҳ�ȥ����\n", me->name(), obj->name()), this);
				message_vision(snprintf(msg, 255, "$HIRֻ����ĺ������һ�ӣ�%s��%s����Я����%sһ�𱻷��˳�ȥ��\n", me->name(),me->name(), obj->name()), this);
				obj->move(load_room("����ɽ������"));
				me->move(load_room("����ɽ������"));
			}
		}
	}	
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[40];

	if (DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��"))
	{
		say("�����Һ��޹ϸ��⻰�Ӻ�˵��",me);
		return;
	}

	if (DIFFERSTR(environment()->querystr("base_name"), "����ɽ�����ȵ�" ))
	{
		say("��������������Ҳ����������г�����",me);
		return;
	}

	if (me->query_int() < 30) 
	{
		say("�ҹ�Ĺ�ɵĹ����һ�����֣�������ʲ�����", me);
		SendMenu(me);
		return;
	}

	if ( me->query_skill("yunv_xinfa",1) < 70 ) 
	{
		say("�����Ů�ķ������,�������Ը�������书��", me);
		SendMenu(me);
		return;
	}
	
	if (me->query("repute")<80000) 
	{
		say("�����������ұ�ѧ���˵Ļ���Ʒ�ʣ������ܶ���Щ����֮�£���һ������Ϊͽ��",me);
		SendMenu(me);
		return;
	}
	if(!me->query("gumu/jq"))
	{
		say("������Ե��������",me);
		SendMenu(me);
		return;
	}	
	say("�ðɣ�����Ҳ���������ˣ��Ҿ����������ͽ���ˡ�",me);
	command(snprintf(msg, 40, "recruit %ld", me->object_id()));
}

NPC_END;



