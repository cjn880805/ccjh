//xiaoyao_qinglong33.h ����������
//�ز� 2002��12��17

XiaoYao_BEGIN(CRXiaoYao_qinglong33);

virtual void create()
{
	set_name( "����������");
	
	add_door("����������2", "��ң������������32", "��ң������������33");
	
	add_door("����������4", "��ң������������34", "��ң������������33");
	
	add_npc("xy_qinglong3");
	add_npc("xy_qinglong3");

	set("����",random(4)+4);
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
		CContainer * ShouWei=present("tian yu");
		if(ShouWei)
		{
			tell_object(me, "$HIR����������ȵ������󵨿�ͽ�������Ҵ����䱦������������������£���");
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}
XiaoYao_END;
