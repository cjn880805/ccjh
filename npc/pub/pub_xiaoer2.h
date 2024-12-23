VENDOR_BEGIN(CNPub_xiaoer2);

virtual void create()
{
	set_name( "��С��", "xiao er");

	set("icon", waiter);
	set("gender", "����" );
	set("age", 25);
	set("long","��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������");
	set("combat_exp", 150);
	set("nkgain", 40);

	set("attitude", "friendly");
	set("no_get", "1");
	set("rank_info/respect", "С����");
	carry_object("cloth")->Do_Action(DO_WIELD);

	carry_good("niupidai", 1000);
	carry_good("qingke_m", 1000);
	carry_good("yaopin_1", 100, 1);
	carry_good("yaopin_1", 100, 3);
	carry_good("yaopin_1", 100, 4);
	carry_good("yaopin_1", 100, 7);
	
	carry_good("yaopin_2", 50, 1);
	carry_good("yaopin_2", 50, 2);
	carry_good("yaopin_2", 50, 3);

	carry_good("huicheng_juanzhou", 200);
};

virtual void init(CChar * me)
{	
	CNpc::init(me);
/*	
	if(me->query("mud_age")==me->query("death/mud_age")
		||me->query_temp("kill/flee")!=me->query("kill/flee")
		||me->query_temp("kill/death")!=me->query("kill/death"))
	{
		char msg[255];
		me->set_temp("block_msg/all",1);
		if(EQUALSTR((me->query_weapon())->querystr("id"), "tealeaf"))
			me->command(snprintf(msg, 40, "unwield %ld", (me->query_weapon())->object_id()));

		me->delete_temp("apply");
		me->delete_temp("block_msg/all");

		me->set_temp("kill/flee",me->query("kill/flee"));
		me->set_temp("kill/death",me->query("kill/death"));
		me->UpdateMe();
	}
*/
	if( ! is_fighting() ) 
	{
		if(me->query("tongji")||me->query("kill/����ʱ��"))
		{
			char msg[255];
			tell_object(me,"�㷢���������ﲢ���ܻ�ӭ��ֻ����ƹ����һ�����㱻�˴ӷ���һ�����˳������Ǳ���״���ӿ��ˡ�");
			tell_room(me->environment(),snprintf(msg,255,"ֻ����ƹ����һ����%s���˴ӷ���һ�����˳������Ǳ���״���ӿ��ˡ�",me->name()),me);
			me->move(load_room(global_room_name[random(MAX_ROOM_NUM)]));
			me->add("hp",-100);
		}
		else if ( EQUALSTR(me->querystr("family/family_name"), "ؤ��" )
			&& me->query_skill("begging",1) > 10 && !me->query_temp("apply/no_����") )
		{
			remove_call_out(do_saying);
			call_out(do_saying, 3, me->object_id());
		}
	}
}

static void do_saying(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

	me->say("�����Ҫ���Ľ�����ʲ�᣿ ���ҹ���ȥ��");
}

VENDOR_END;




