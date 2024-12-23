// pub_laoban.c
//code by Fisho
//date : 2000-12-14
//inherit F_DEALER;

VENDOR_BEGIN(CNpub_laoban);

virtual void create()
{
	set_name("�ƹ��ϰ�", "lao ban" );

	set("icon", pub_boss);
	set("gender", "����" );
	set("age", 32);
	set("long","��λ�ƹ��ϰ��������㣬��ͷ�����Ŷ���Ц�š�");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("no_get", "1");
	carry_object("cloth")->wear();
	carry_good("gourou",500);
	carry_good("gouroutang",500);
	carry_good("map",500);
}

virtual void init(CChar *ob)
{	
	CNpc::init(ob);
	if( userp(ob) && !is_fighting() ) 
	{
		if ( EQUALSTR(ob->querystr("family/family_name"), "ؤ��") 
			&& ob->query_skill("begging",1) > 10 )
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
		return "�ƹ��ϰ�����˵������ô����죬���빷����������ů�����ӵģ�";
	case 1:
		return snprintf(msg,255,"�ƹ��ϰ���˴��֣�˵������λ%s������󲹰��������ɡ�",query_respect(ob));
	}
	return "";
}

static void saying(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *) (me->environment())->Present(param1);

	if (! who) return ;
	
	message_vision("$N���һ���������Ҫ���Ľ�����ʲ�᣿ ���ҹ���ȥ��", me);
	me->remove_call_out(kicking);
	me->call_out(kicking, 1, param1);
}

static void kicking(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	char msg[255];

	if (! who) return;
	
	who->move(load_room("������Զ"));//û�иó���
	tell_room(who->environment(),snprintf(msg,255,"ֻ����ƹ����һ����%s���˴��������һ�����˳������Ǳ���״���ӿ��ˡ�",who->name() ),who);
}
VENDOR_END;