// pub_xiaoer3.c �Ƶ�С��
//code by Fisho
//date : 2000-12-14
//inherit F_DEALER;

VENDOR_BEGIN(CNpub_xiaoer3);

virtual void create()
{
	set_name("��С��",  "waiter"  );

	set("icon", waiter);
	set("gender", "����" );
	set("age", 22);
	set("long","��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������");
	set("combat_exp", 100);
	set("nkgain", 30);

	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("no_get", "1");
	carry_object("cloth")->wear();

	carry_good("fotiaoqiang");	
}

virtual void init(CChar *ob)
{	
	CNpc::init(ob);
	if( userp(ob) && !is_fighting() )
	{
		if ( EQUALSTR(ob->querystr("family/family_name"), "ؤ��") 
			&& ob->query_skill("begging", 1) > 10 )
		{
			remove_call_out(saying);
			call_out(saying, 1, ob->object_id());
		}
	}
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	switch( random(2) )
	{
		case 0:
			return snprintf(msg,255,"��С��Ц�����˵������λ%s�������ȱ��裬ЪЪ�Ȱɡ�",query_respect(ob));
		case 1:
			return snprintf(msg,255,"��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ%s����������",query_respect(ob));
	}
	return "";
}

static void saying(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *) ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if (!who) return;
	
	me->say("��С�����һ���������Ҫ���Ľ�����ʲ�᣿ ���ҹ���ȥ��");

	me->remove_call_out(kicking);
	me->call_out(kicking, 1, param1);
}

static void kicking(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *) ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	char msg[255];

	if (!who) return;
	
	who->move(load_room("����"));//û�иó���
	tell_room(who->environment(),snprintf(msg,255, "ֻ����ƹ����һ����%s���˴�ζ��ζ��һ�����˳������Ǳ���״���ӿ��ˡ�", who->name() ), who);
}

VENDOR_END;