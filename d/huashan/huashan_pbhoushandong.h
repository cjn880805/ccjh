//huashan_pbhoushandong.h ��ɽ�ٲ���ɽ��

ROOM_BEGIN(CRHuaShan_pbhoushandong);

virtual void create()			//Call it when Room Create
{
	set_name( "��ɽ�ٲ���ɽ��");
	add_door("��ɽɽ���ٲ�", "��ɽɽ���ٲ�", "��ɽ�ٲ���ɽ��");
	add_npc("was_shuangmu");
	
	set("long", "����ԭ�����ж��죬���Ŷ���΢���Ĺ⣬��ֻ��һ������������");  
	
};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query_temp("was/renwu1_1") && !me->query_temp("was/renwu1_2"))
		{
			me->set_temp("was/renwu1_2",1);//����˫ľʦ��(��ɽ��)
			tell_object(me,"\n$HIC����ԭ�����ж��죬���Ŷ���΢���Ĺ⣬��ֻ��һ������������");
			tell_object(me,"$HIC���������ֳ�ľ������������̣������佣ʽ�����޷��������Ĺ�������Ϊ����û����ʽ�����޿ɷ��ϣ����õ��ǽ�����\n");
			tell_object(me,"$HIC�㽥����Ӧ���ڻ谵������Ȼ������ǰ�˵���ף���������ԭ����ʧ�ٶ����˫ľʦ�֡���\n");
		}
	}
}

ROOM_END;
