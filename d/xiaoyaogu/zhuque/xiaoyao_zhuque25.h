//xiaoyao_zhuque25.h ��ȸ������
//�ز� 2002��12��17

XiaoYao_BEGIN(CRXiaoYao_zhuque25);

virtual void create()
{
	set_name( "��ȸ������");
	
	add_door("��ȸ������4", "��ң����ȸ������24", "��ң����ȸ������25");
	
	add_door("��ȸ������6", "��ң����ȸ������26", "��ң����ȸ������25");
	
	add_npc("xy_zhuque2");
	add_npc("xy_zhuque2");

	set("����",random(5)+3);
	set("λ��",random(2)+1);
	set("����","��ȸ");
	
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
		CContainer * ShouWei=present("zhu");
		if(ShouWei)
		{
			tell_object(me, "$HIR��ȸ������ȵ������󵨿�ͽ�������Ҵ���ȸ��������������������£���");
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}
XiaoYao_END;
