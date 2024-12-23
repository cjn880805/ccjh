//xiuxishi.h

//Sample for room:  ÷ׯ��Ϣ��
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRMeiZhuang_xiuxishi);

virtual void create()			//Call it when Room Create
{
	set_name( "÷ׯ��Ϣ��");

	add_door("÷ׯ����2", "÷ׯ����2", "÷ׯ��Ϣ��");

	set("sleep_room", 1);
    set("no_fight", 1);

	set("valid_startroom", 1);

};

virtual int do_look(CChar * me)
{
	CContainer * yaosi;
	yaosi=me->present("yao si");
	if(yaosi && yaosi->query("ry/yaosi") && EQUALSTR(yaosi->querystr("owner1"), me->id(1)) && me->query_temp("ry/renwu1_2") && !me->query_temp("ry/renwu1_3"))
	{
		tell_object(me,"\n$HIR����ϸ������Ϣ�ң��۹��Ĵ������š���Ȼ�㿴����Զ���ĵ�������һ��СС�ķ�϶���ƺ���һ�����ס�");
		tell_object(me,"$HIR���ͳ����е�Կ�ף�������϶�С�");
		tell_object(me,"$HIR�ӿ���ƽ�������ʯͷ���澹�����п�һ����϶��¶��һ��ͨ����û�뵽÷ׯ���»���������˾��ܣ����������������治�������ڹŴ��й��Ѿ�������ô�õ�ʯ��������");
		me->move(load_room("÷ׯˮ��ʯ��"));
		me->set_temp("ry/renwu1_3",1);//����ˮ��ʯ��
		destruct(yaosi);
	}
	else
	{
		say("����û��ʲô�ر�ġ�",me);
		SendMenu(me);
	}
	return 1;
}

ROOM_END;
