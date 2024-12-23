//xiaoyao_shishi4.h ��ߧ����ʯ��4
//�ز� 2003��3��15

XiaoYao_BEGIN(CRXiaoYao_shishi4);

virtual void create()
{
	set_name( "ʯ��4");
	set("no_autosave",1);
	set("long","������Բ��ʯ�ң��ı���ʯ��ĥ�����ǹ⻬��ʯ���Ͽ������������������ԲȦ��ÿ��Ȧ�ж����˸��ָ�����ͼ�Ρ���");

	add_door("��ߧ����", "��ң����ߧ����", "��ң����ߧ����ʯ��4");
	set("index",4);
	add_item("shiguei");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query_temp("xy/renwu6_4") && me->query("xy/renwu6") && !me->query("xy/renwu6_1"))
	{
		say("�㷢�ֳ���ǽ���������⣬�ذ��ϸ�ӡ�������ҵĽ�ӡ������������ϰһ�ֺܸ���Ĳ�����", me);
		if(me->query_skill("lingboweibu",1)>200)
			AddMenuItem("��ϰ����", "$0lianxi $1", me);
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(!me->query_temp("xy/renwu6_4") || !me->query("xy/renwu6") || me->query("xy/renwu6_1"))
		return 0;
	if(!strcmp(comm, "lianxi") && me->query_skill("lingboweibu",1)>200)
		return do_lianxi(me, arg);
	return 0;
}


int do_lianxi(CChar *me, char * arg)
{
	if (me->is_busy())
		return notify_fail("��������æ���ء�");
	
   	tell_object(me, "\n$HIR����ϸ��ĥ�ŵ��µĲ��������ҿ�����������鲻�Խ��İ��ս�ӡ��������������");
	me->set_temp("block_msg/all",1);
	me->disable_player("��ϰ��");
	me->call_out(wakeup, random(5)+1);
	return 1;
}

static void wakeup(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	char msg[255];
	if(!me) return;

	me->delete_temp("block_msg/all");
	me->enable_player();

	while( (me->environment())->is_character() )
		me->move((me->environment())->environment());
	
	LONG need_points =  me->skill_need_points("lingboweibu");
	LONG need_exp = 4*(need_points / me->learn_bonus() + 1);
	if(need_exp<3000)need_exp=3000+random(1500);
	
	if(me->query_valid_exp() < need_exp)
	{
		tell_object(me, "\n$HIR��Ȼ�䣬����û�������Խ��Խʢ���ӵ����в���ӿ������������������������ͻ��Ծ���ѹ�֮����");
		tell_object(me, snprintf(msg, 255, "$HIR�����׵����Լ��Ľ��������������޷���ȥ��ϰ���ϸ���Ĳ��������ɵ�̾�˿�����ѧϰ%s����%ld�㾭�飩��\n", me->querystr_temp("lj/skill_id"), need_exp));
	}
	else if(me->query("pro/skill/lingbo_weibu")>me->query("xkd/xy"))//�Ѿ�ѧ����
	{
		tell_object(me, "\n$HIR��Ȼ�䣬��ֻ����һ��ͷ�����ͣ��޷���������ȥ��ϰ���ϸ���Ĳ�����");
		tell_object(me, "$HIR�����׵����Լ����书�����Ѿ���ʱ�޷�ͻ�������ˣ����ɵ�̾�˿�����");
	}
	else
	{
		tell_object(me,"$HIR\n���²������֣���һ·������ȥ����ʱ������һ�����޷��ӵ���һ����ֱ���뵽���ƾ��תһ������ż�������Ȼ�Ľ����ˡ�");
		tell_object(me,"$HIR��ʱ����Ծǰ�ݺ��������������������б��ûһ����ֱ���ˡ�");
		tell_object(me,"$HIRϸ��֮��һ����⣬��Ȥ֮��ʵ������������\n");
		if(me->query_temp("xy/lingbo_weibu")<1000)	
		{
			tell_object(me, snprintf(msg, 255,"$HIR��ƾ����ḻ�Ľ�������(-%d)�����貨΢��������������һ�㡣\n",need_exp));	
			me->add_temp("xy/lingbo_weibu",15+2*random(me->query_int()));
		}
		else
		{
			tell_object(me, "$HIC����²���Խ��Խ�죬�������貨����ӯ�鶯������ʵ�Ϸ����Ʈ��������\nͻȻ��������ᣬ�����˻�Ȼ���������$HIW���貨΢����$HIC�ľ�Ҫ���ڣ�ϰ��$HIW���貨΢����$HIC֮$HIW�������貨��$HIC��");
			me->set("pro/skill/lingbo_weibu",1);
			me->delete_temp("xy/lingbo_weibu");
			me->set("xy/renwu6_1",1); //��ϰ�����貨΢��֮�����貨
		}
		me->add("combat_exp",-need_exp);
	}
	me->FlushMySkill(me);
	me->UpdateMe();
}

XiaoYao_END;
