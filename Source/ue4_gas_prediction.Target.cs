// Richard Hähne 2019

using UnrealBuildTool;
using System.Collections.Generic;

public class ue4_gas_predictionTarget : TargetRules
{
	public ue4_gas_predictionTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "ue4_gas_prediction" } );
	}
}
