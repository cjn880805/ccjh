//wulin_jichugu.h �ó���
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_jichugu);

virtual void create()			
{
	set_name("�ó���");

	add_door("���괺�ش���","���괺�ش���", "���괺�ó���");

};

virtual int valid_leave(CChar * me, const char * dir)
{
	CContainer * env=me->environment();
	if(env->query("no_move") )
	{
		if(me->querymap("lj"))
		{
			message_vision("$HIR�㿴��Ⱥ�鼤������Ⱥ���ŵĲ��Ҷ�����", me);
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);

}
WL_END;
