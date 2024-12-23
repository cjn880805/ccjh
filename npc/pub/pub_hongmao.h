NPC_BEGIN(CNpub_hongmao);

virtual void create()
{

	set_name("��ë��","hongmao");

	set("icon", banditi);
	set("gender", "����");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "�������쳯����̨��ĺ�����ë�������϶���һ֧��ǹ��ǹ�ڻ�ð�����̡�");
	set("combat_exp", 25000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 30);

	carry_object("huoqiang")->wield();

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
	CChar * who = (CChar *)(ob->environment())->Present(param1);

	if(! who) return;

	who->receive_damage("hp",50);
	who->receive_wound("hp",50);
	
	message_vision("��ë��̧�־���һǹ���飡ǹ��һ�Ż��������", who);
	who->SendState(who);
}

NPC_END;
