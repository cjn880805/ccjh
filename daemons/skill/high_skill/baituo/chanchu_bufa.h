//chanchu_bufa.h   ��ܲ���

//code by Fisho
//date : 2000-11-29

SKILL_BEGIN(CSchanchu_bufa);

virtual void create()
{
	set_name( "��ܲ���");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80]=
	{
	"ֻ��$nһ�С��ɾ��졹���������ϱ�ֱ���������࣬�����$N��һ�С�",
	"����$nһ��ʹ�����������졹������Ʈ��������һ�ݣ����ѱܿ���",
	 "$nһ�С����뵾�����������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�",
	"����$nһ��������˳桹������һ�ã�$N��һ�����˸��ա�",
	"ȴ��$n��󸷭�׶ǡ����㲻��أ����Դܿ����ߣ����˿�ȥ��",
	"$n����һ�С������¡�������΢�Σ��о����յرܿ���$N��һ�С�"
	};
	
	return dodge_msg[random(6)];
}

virtual int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

virtual int valid_learn(CChar * me) { return 1; }

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 45 )
		return notify_fail("�������̫���ˣ���������ܲ�����");
	me->receive_damage("hp", 35);
	return 1;
}

SKILL_END;