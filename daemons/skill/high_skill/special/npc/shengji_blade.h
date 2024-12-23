//shengji_blade.h �������

SKILL_BEGIN(CSshengji_blade);

virtual void create()
{
	set_name( "�������");

}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  damage, dodge,  parry;
		char damage_type[5];
	}action[] = {
		{"$N���ϸ��ֳ�һ˿�����Ц�ݣ�ͻȻʹ��һ�С�Ц��ص���������$wֱ��$n��$l��",70,-10,200,"����"},
		{"$Nʹ��һ�С��û��١�����$w�����������⣬ӳ��$n�ۻ����ң��û�ƽ��$n��$l��",140,-10,100,"����"},
		{"$N������Σ�$w����һ�С������������ݺݿ���$n��$l��",160,-10,100,"����"},
		{"$N����һ����һ�С����׳�н����$w��$n��$lбб�ó�һ����",180,-10,10,"����"},
		{"$N����$w�ó����쵶�⣬һ�С���ˮ���㡹��������ɣ�������Ϣ��ת��$n�ı����Ͷ�$n��$l��",210,-10,100,"����"},
		{"$N��$w�߻��Σ�һ�С����Ŵ򹷡�����ס$n����·������ֱ��$n��$l��",230,-10,100,"����"},
		{"$Nһ�С�������������$w�ҷ磬���϶��£������㿳��$n��$l��",200,-40,100,"����"},
		{"$Nһ�С���ݾ��ߡ���$w�����񿳣�����$n�ľ���ս��",300,-200,100,"����"},
		{"$Nʹ��һ�С�˳��ǣ�򡹣�$w������������$n����һ����б����˳��һ����",220,-10,100,"����"},
		{"$N����һ��������$w�󿪴�ϣ�һ�С�Զ������������Բ���������磬��$n����Χס��",200,-10,80,"����"},
		{"$N����$wһ�С���;��뽡������˺�һ����ɱ��ȥ��ͻȻ����һ��������$n��$l��",120,-200,-100,"����"},
		{"$Nһ�С��赶ɱ�ˡ������������һ������$n��$l��",120,-200,-100,"����"},
	};
 
  	int level = random(12);

	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	m_actions.set("damage", action[level].damage);
		
	return & m_actions;
};

virtual const char * query_parry_msg(CContainer * weapon)
{
	static char parry_msg[][255] = {
		{"$nʹ��һ�С�͵��������������$W���һ�У�ͻȻ���л�ʽ����ס$n��ȫ��"},
		{"$n����$W��̣���;ͻȻ��ת��һ�С�ָɣ�������סȫ��Ҫ����"},
		{"$nһ�С���ʬ���꡹����Ӱ��������Ʈ��ԭ�أ�����$W��������һ���Ŀ���$N��$w��"},
		{"$nһ�С�������ɽ����������Σ���$N����ʽ������$WȴֱϮ$N֮�ؾȡ�"},
		{"$nһ�С�����Ϊ�����������е�$W������$N����ʽ��"},
		{"$n���ⶪ��������һ�С���ש���񡹣�����$W������$N֮�ؾȡ�"},
		{"$n����$W��÷��겻͸��һ�С�������������Ƶ�$N���ֳ��С�"},
		{"$nһ�С�Χκ���ԡ���ȫȻ����$N�Ĺ�����$Wֱ��$N��ȥ���Ƶ�$N�����Ա���"},
	}; 
	if( weapon )
		return parry_msg[random(4)];
	else
		return parry_msg[random(4)+4];
}

virtual int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	return 0;
}

virtual int practice_skill(CChar * me)
{
	return 0;
}

SKILL_END;


