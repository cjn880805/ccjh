//xiaoyao_xuanwu23.h ����������
//�ز� 2002��12��17

XiaoYao_BEGIN(CRXiaoYao_xuanwu23);

virtual void create()
{
	set_name( "����������");
	
	add_door("����������2", "��ң������������22", "��ң������������23");
	
	add_door("����������4", "��ң������������24", "��ң������������23");
	
	add_npc("xy_xuanwu2");
	add_npc("xy_xuanwu2");
	
	set("����",random(5)+3);
	set("λ��",random(2)+1);
	set("����","����");
	
};

int valid_leave(CChar * me, const char * dir)
{
	if(userp(me))
	{
		if(!me->query("xy/renwu4_3"))
		{
			me->move(load_room("��ɽ������"));
			return 0;
		}
		else if(!me->query_temp("xy/renwu4_1"))
		{
			tell_object(me, "\n$HIRͨ������һƬ�����滹��ʱ����һЩ�����������ֻ�ŵ����ľ������������ٽ�ǰһ�����������ǵ���ʦ������ʦ�������Ϊ��׳׳����\n");
			me->move(load_room("��ң�ȿյ�"));
			return 0;
		}
		CContainer * ShouWei=present("yu qiang");
		if(ShouWei)
		{
			tell_object(me, "$HIR����������ȵ������󵨿�ͽ�������Ҵ����䱦������������������£���");
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}
XiaoYao_END;
