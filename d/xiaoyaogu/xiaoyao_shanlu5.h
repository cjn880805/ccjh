//xiaoyao_shanlu5.h ɽ·5
//�ز� 2002��12��5

XiaoYao_BEGIN(CRXiaoYao_shanlu5);

virtual void create()
{
	set_name( "ɽ·5");

	add_door("��ң��������ɽ·4", "��ң��������ɽ·4", "��ң��������ɽ·5");	
	add_door("��ң�ȿյ�", "��ң�ȿյ�", "��ң��������ɽ·5");	
	add_door("��ң�ȴ���Ǿ���1", "��ң�ȴ���Ǿ���1", "��ң��������ɽ·5");

};


int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"����Ǿ���1"))
	{
		if(me->query("xy/renwu7_1") && !me->query("xy/renwu8"))
			return CRoom::valid_leave(me, dir);
		else
			return notify_fail("�㿴�ž�������Ĵ������񣬸�Լ�ĳߣ����״��У��ֳָ��ᣬ����ׯ�ء�������̤��ū��һ��ū���Ⱪ���������ߣ�����������ū����������ū���͡�һ�����������ˣ��м�һ������˫�ָ�������һ�㣬����֮�������ķ𾭣���ʱ��Ȼ�𾴡�");;
	}
	return CRoom::valid_leave(me, dir);
}

XiaoYao_END;
