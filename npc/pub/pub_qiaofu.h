// pub_qiaofu.c

// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_qiaofu);

virtual void create()
{
	set_name("�Է�","qiao fu");

	set("icon", old_man1);
	set("gender", "����" );
	set("age", 50);
	set("long", "һ��һ�����Կ���Ϊ�������Է����ڱ��ܷ�˪���Գ������䲻��Ƶ�˥�ϡ�");
	set("shen_type",1);
	set("combat_exp", 10000);
	set("str", 17);
	set("dex", 18);
	set("con", 18);
	set("int", 18);
	set("attitude", "friendly");
	set_inquiry("��",inquiry_dao);
 	set_temp("buyed", 0l);
	carry_object("cloth")->wear();
	set("no_huan",1);
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	command("smile");
	say("лл���ĵĴ�ү�������кñ���", who);
	if( EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 3000  )
		who->set_temp("buyed", 1);

	SendMenu(who);
	destruct(ob);
	return 1;
}

static char * inquiry_dao(CNpc *who,CChar *me)
{
	CContainer *obj;
	if (me->PresentName("chaidao",IS_ITEM))
		return "��ͱ�Ѱ��ͷ�ӿ����ˣ������ϲ���Ҳ��һ����?";
	
	if( me->query_temp("buyed")==0 )
		return "��λ��ү��ʵ�ڲ������᲻���⵶��С��һ�Ҿ�ȫ�����������ˣ������㣬������ô�����";

	if( me->query_temp("buyed")==1 )
	{
		who->say("��Ȼ��������Ҫ���͸���ɣ�����ʷ����Ҫ�Һúñ��ܵģ����ǧ���Ϲ�͸����ˣ��������������ġ�", me);
		obj = load_item("chaidao");//��
		obj->move(me);
		message_vision("�Է�ݸ�$Nһ�Ѳ񵶣�", me);
		me->set_temp("buyed", 0l);

		who->SendMenu(me);
	}

	return "";
}

NPC_END;