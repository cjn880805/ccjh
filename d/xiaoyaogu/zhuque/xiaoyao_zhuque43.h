//xiaoyao_zhuque43.h ��ȸ���Ĳ�
//�ز� 2002��12��17

XiaoYao_BEGIN(CRXiaoYao_zhuque43);

virtual void create()
{
	set_name( "��ȸ���Ĳ�");
	
	add_door("��ȸ���Ĳ�2", "��ң����ȸ���Ĳ�42", "��ң����ȸ���Ĳ�43");
	
	add_door("��ȸ���Ĳ�4", "��ң����ȸ���Ĳ�44", "��ң����ȸ���Ĳ�43");
	
	add_npc("xy_zhuque4");
	add_npc("xy_zhuque4");

	set("����",random(3)+5);
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
		CContainer * ShouWei=present("jiou feng");
		if(ShouWei)
		{
			tell_object(me, "$HIR��ȸ������ȵ������󵨿�ͽ�������Ҵ���ȸ��������������������£���");
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}
XiaoYao_END;
