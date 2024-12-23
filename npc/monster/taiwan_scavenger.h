//scavenger.h
//Teapot 2000-01-05

NPC_BEGIN(CNtaiwan_scavenger);

virtual void create()
{
	set_name("�����õ�", "Scavenger");
	set("long", "��һ��Ʈ�ݵİ�ɫ��������ҡ���ȣ��������š�");
	set("title", "[�չ�����]");
	set("gender", "����");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_man3);

	set("rubbish", 1);
};

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	char msg[255];

	if(! who) return;

    message_vision(snprintf(msg, 255, "$N����$n̾��һ����������λ%s, ��������С�ģ����������ɡ�", query_respect(who)), me, who);

	return;
}

NPC_END;
