// pub_zhuangyu.c
// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_zhuangyu);

virtual void create()
{
	set_name("ׯ�ʳ�", "zhuang yuncheng" );

	set("icon", young_man2);
	set("gender", "����" );
	set("age", 40);
	set("int", 28);
	set("long","���Ǹ�����ʫ�飬ȴ���޲���֮������������༭����ʷ���ԡ����������ٸ淢��ȫ�Ҵ��뾩�С�" );
	
	set("attitude", "peaceful");
	set_skill("literate", 100);
	set("no_get", "ׯ�ʳ�̾�����Ҳ����ˣ����߰ɡ������ҵ����Ҽ����˰���");
	set("chat_chance", 5);

	set_inquiry("����","����ʵ��̫�ɶ��ˡ�");
	set_inquiry("�鷿","�鷿���Ƿ�������Ư���ɣ�");
	set_inquiry("����","�Һ�ϲ�����滭���Ǹ�Ů����");
	set_inquiry("����","������ھͺ��ˣ�һ������Ҿȳ�ȡ�á�");
	set_inquiry("����","�Ǹ��������Ů���Ӻ���һֱ�������ơ�");
	set_inquiry("���ƵĽ�", "��˵�ǰѽ��������� ");
	set_inquiry("��������", ask_weiwang);

	carry_object("cloth")->wear();
	set("no_huan",1);
}

virtual char * chat_msg()
{
	switch (random(5) )
	{
	case 0:
		return "ׯ�ʳ�˵����ֻ���ҵ������ģ������м��˽�Ҷ��������˭�������Ĺ��εļһﾹȻ��ȥ�淢���ҡ���...";
	case 1:
		return "ׯ�ʳ�˵����˭Ҫ��������ץ������������ͺ��˾ͺ��ˡ�";
	case 2:
		return "ׯ�ʳ�̾��: �����Թſ���ޣ��˺������޾��ڡ�";
	case 3:
		return "ׯ�ʳ�̾�˿�����˵������֪������ı�������ܣ�ֻ��ϧ������";
	case 4:
		return "ׯ�ʳ�˵����˭Ҫ�����ң���һ�����ҵ�Ů�����͸�����";
	}
	return "";
}

static char * ask_weiwang(CNpc *ob,CChar *me)
{
	char msg[255];
	tell_object(me,snprintf(msg,255," �����ڵĽ���������%ld " , me->query("weiwang") ));
	ob->say("���������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����", me);
	ob->say("�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������", me);
	ob->say("ɱĳЩ���˻��ĳЩ���˿�����߽���������", me);
	ob->SendMenu(me);
	return "";
}

virtual void init(CChar *me)
{
	char msg[255];
	if(!userp(me)) return;
	if(userp(me) && !is_fighting() ) 
		say( snprintf(msg,255,"ׯ�ʳǹ���Ц�������������������ˣ���λ%s�������ı����ɲ��ٰ�����Ҫ��ʲô�����׵ģ��������Ұɡ�",query_respect(me) ));

	if(me->query("weiwang")<20) 
	{
        me->add("weiwang",10);
		message_vision(  "$N�Ľ�����������ˣ�"  ,me);
	}

	command(snprintf(msg,255,"tell %ld �����ڵĽ���������%ld ",me->object_id(),me->query("weiwang") ));
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if ( !(ob) ) return 0; 
//	if ( !present(ob,me) return notify_fail("��û�����������");
	if (  EQUALSTR( ob->querystr("name"), "��ʷ����") )
	{
		say("�����н�Ҷ�ӣ��ѵ��㲻֪����", me);
		say("���Ұ�����������ץ��ׯ��ȥ�ɣ��Ҳ����ˡ�", me);		
		say("ׯ�ʳǴ��˿�������˵��ׯ���ھ��Ƕ����ߡ�", me);
		SendMenu(me);
	}		

	return 1;
}

NPC_END;