ITEM_BEGIN(CIguanyin);

virtual void create(int nFlag = 0)		
{
	set_name( "�����ױ��������");	
	set("no_get", "�ѹ�����͵�ߣ�������Ҳ̫�����쿪�˰ɡ�");
	set_weight(1);
};

virtual int do_look(CChar * me)
{
	say("�����ױ��һ�������", me);
	AddMenuItem("���¿�ͷ", "$0kneel $1", me);
	AddMenuItem("ת���뿪", "", me);
	SendMenu(me);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "kneel") == 0)
		return do_kneel(me, arg);
	return 0;
}

int do_kneel(CChar *me, char * arg)
{
	me->receive_damage("hp",50);	
	message_vision("$N���������ĸ�����������˸�ͷ��", me);   
	
	me->add_temp("teapot/guanyin",1);

	if (me->query_temp("teapot/guanyin")==3)
	{
		me->set_temp("teapot/guanyin",0l);
		message_vision("����������������ƺ��������������$N΢΢һЦ��", me);   
		tell_object(me,"��ֻ��������һƬ�������������������ϵĵĶ���ԹԹ��");
		me->remove_all_killer();
		me->delete_temp("teapot/bot");
		return 1;
	}

	return 1;
	

}

ITEM_END;
