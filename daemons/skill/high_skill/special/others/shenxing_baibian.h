// shenxing_baibian.c ���аٱ�
//by sound
//2001-07-21

SKILL_BEGIN(CSshenxing_baibian);

virtual void create()
{
	set_name( "���аٱ�");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80]={
		{"$nһʽ��������ˮ���������㣬�Ų��ƣ�������������ˮ��ֱ�������ࡣ",},
		{"$nһʽ��Ǳ��ҹ�С�����Ȼһ������ȫ�����ض��У���ʱ������$N���������ơ�",},
		{"$nһʽ���Ʋ����Ρ����㲻�����ֲ�̧��һת�ۼ���Ƶ���$N������",},
		{"$nһʽ��������Ӱ����һת���䣬����˷�Ʈ����������$n����Ӱ����$N�����޴롣",},
		{"$nһʽ���貨΢��������̤�㣬��תǬ������һ�Σ��㵽����Զ�ĵط���",},
		{"$nһʽ�����ϲ�¥�������ڿ��У������������һ�㣬��$Nͷ���ڿն�����",},
		{"$nһʽ�����ӳ�ˮ��������һ����ȫ����Ϊһ����Ӱ�����ĵش�$Nͷ��Ʈ�䡣",},
		{"$nһʽ�����·ת�������������ݰ㼱ת����ʱһ������ӿ������$N���Զ�����",},
		{"$nһʽ�������ﲨ��������ٿ�Ĵ�$N����ǰֱ�Ƶ�����$N�ɴ������ۣ��������ԡ�",},
		{"$nһʽ�����ӻ�ͷ��������ٿ�Ĵ�$N����ǰƮ��������һ˦������֮����",},
	};
	
	return dodge_msg[random(10)];
}

virtual int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

SKILL_END;
